<?php
namespace Apigee\Mint;

use Apigee\Mint\Exceptions\MintApiException as MintApiException;
use Apigee\Exceptions\ResponseException as ResponseException;
use Apigee\Mint\Types\MonthType as MonthType;
use Apigee\Mint\DataStructures\BillingMonth as BillingMonth;
use Apigee\Exceptions\ParameterException as ParameterException;

class BillingDocument extends Base\BaseObject
{

    /**
     * @var \Apigee\Mint\Organization
     */
    private $organization;

    /**
     * @var array of \Apigee\Mint\Product
     */
    private $product;

    /**
     * @var array of \Apigee\Mint\Organization
     */
    private $subOrg;

    /**
     * @var array of \Apigee\Mint\Developer
     */
    private $developer;

    /**
     * @var \Apigee\Mint\Developer
     */
    private $billableDeveloper;

    /**
     * @var \Apigee\Mint\Organization
     */
    private $billableExchangeOrg;

    /**
     * @var string
     */
    private $startDate;

    /**
     * @var string
     */
    private $endDate;

    /**
     * @var string
     */
    private $billingMonth;

    /**
     * @var int
     */
    private $billingYear;

    /**
     * @var string
     */
    private $status;

    /**
     * @var string
     */
    private $type;

    /**
     * @var string
     */
    private $documentNumber;

    /**
     * @var string
     */
    private $currency;

    /**
     * @var double
     */
    private $amount;

    /**
     * @var double
     */
    private $taxAmount;

    /**
     * @var string
     */
    private $dueDate;

    /**
     * @var string
     */
    private $batchId;

    /**
     * @var string
     */
    private $paymentDueDays;

    /**
     * @var string
     */
    private $billingDocDate;

    /**
     * @var string
     */
    protected $id;

    private $file;

    private $fileMimeType;

    public function __construct(\Apigee\Util\OrgConfig $config)
    {
        $base_url = '/mint/organizations/' . rawurlencode($config->orgName) . '/billing-documents';
        $this->init($config, $base_url);

        $this->wrapper_tag = 'billingDocument';
        // TODO: verify the following two items when docs are fleshed out
        $this->idField = 'id';
        $this->idIsAutogenerated = true;

        $this->initValues();
    }

    public function getBillingDocuments($developer_id, $billing_month, $billing_year, $received = true, $all = false)
    {
        $dev_criteria = new \stdClass();
        $dev_criteria->id = $developer_id;
        $dev_criteria->orgId = $this->config->orgName;

        $comm_criteria = new \stdClass();
        $comm_criteria->billingMonth = $billing_month;
        $comm_criteria->billingYear = $billing_year;
        $comm_criteria->devCriteria = array($dev_criteria);

        $received = (bool)$received ? 'true' : 'false';
        $all = (bool)$all ? 'true' : 'false';

        $options = array(
            'query' => array(
                'received' => $received,
                'all' => $all,
            )
        );
        $url = '/mint/organizations/' . rawurlencode($this->config->orgName) . '/search-billing-documents';

        $content_type = 'application/json; charset=utf-8';
        $accept_type = 'application/json; charset=utf-8';

        $this->setBaseUrl($url);
        $this->post(null, json_encode($comm_criteria), $content_type, $accept_type, $options);
        $this->restoreBaseUrl();
        $response = $this->responseObj;
        $docs = array();
        foreach ($response[$this->wrapper_tag] as $doc) {
            $bill_doc = new BillingDocument($this->config);
            $bill_doc->loadFromRawData($doc);
            $docs[] = $bill_doc;
        }
        return $docs;
    }

    public function listBillingMonths($id = null)
    {
        $url = '/mint/organizations/' . rawurlencode($this->config->orgName) . '/billing-documents-months';
        $this->setBaseUrl($url);
        $this->get();
        $this->restoreBaseUrl();
        $data = $this->responseObj;

        $months = array();
        foreach ($data as $item) {
            $months[] = new BillingMonth($item);
        }
        return $months;
    }

    protected function initValues()
    {
        $this->organization = null;
        $this->product = array();
        $this->sub_org = array();
        $this->developer = array();
        $this->billableDeveloper = null;
        $this->billableExchangeOrg = null;
        $this->startDate = null;
        $this->endDate = null;
        $this->billingMonth = null;
        $this->billingYear = null;
        $this->status = null;
        $this->type = null;
        $this->documentNumber = null;
        $this->currency = null;
        $this->amount = 0;
        $this->taxAmount = 0;
        $this->dueDate = null;
        $this->batchId = null;
        $this->paymentDueDays = null;
        $this->billingDocDate = null;
        $this->id = null;
        $this->file = null;
        $this->fileMimeType = null;
        // TODO
    }

    public function instantiateNew()
    {
        return new BillingDocument($this->config);
    }

    public function loadFromRawData($data, $reset = false)
    {
        if ($reset) {
            $this->initValues();
        }

        $excluded_properties = array(
            'organization',
            'product',
            'subOrg',
            'developer',
            'billableDeveloper',
            'billableExchangeOrg',
        );

        foreach (array_keys($data) as $property) {
            if (in_array($property, $excluded_properties)) {
                continue;
            }

            // form the setter method name to invoke setXxxx
            $setter_method = 'set' . ucfirst($property);

            if (method_exists($this, $setter_method)) {
                $this->$setter_method($data[$property]);
            } else {
                self::$logger->notice('No setter method was found for property "' . $property . '"');
            }
        }

        if (isset($data['organization'])) {
            $organization = new Organization($this->config);
            $organization->loadFromRawData($data['organization']);
            $this->organization = $organization;
        }

        if (isset($data['product'])) {
            foreach ($data['product'] as $product_item) {
                $product = new Product($this->config);
                $product->loadFromRawData($product_item);
                $this->product[] = $product;
            }
        }

        if (isset($data['subOrg'])) {
            foreach ($data['subOrg'] as $sub_org_item) {
                $organization = new Organization($this->config);
                $organization->loadFromRawData($sub_org_item);
                $this->subOrg[] = $organization;
            }
        }

        if (isset($data['developer'])) {
            foreach ($data['developer'] as $dev_item) {
                $dev = new Developer($this->config);
                $dev->loadFromRawData($dev_item);
                $this->developer[] = $dev;
            }
        }

        if (isset($data['billableDeveloper'])) {
            $dev = new Developer($this->config);
            $dev->loadFromRawData($data['billableDeveloper']);
            $this->billableDeveloper = $dev;
        }

        if (isset($data['billableExchangeOrg'])) {
            $organization = new Organization($this->config);
            $organization->loadFromRawData($data['billableExchangeOrg']);
            $this->billableExchangeOrg = $organization;
        }
    }

    public function __toString()
    {
        $obj = array();
        $properties = array_keys(get_object_vars($this));
        $excluded_properties = array_keys(get_class_vars(get_parent_class($this)));
        foreach ($properties as $property) {
            if (in_array($property, $excluded_properties)) {
                continue;
            }
            if (isset($this->$property)) {
                $obj[$property] = $this->$property;
            }
        }
        return json_encode($obj);
    }

    public function getId()
    {
        return $this->id;
    }

    // Used in data load invoked by $this->loadFromRawData()
    private function setId($id)
    {
        $this->id = $id;
    }

    public function getFile()
    {
        if (!isset($this->file)) {
            if (!isset($this->documentNumber)) {
                throw new ParameterException('Cannot load file for a Billing Document with no document number.');
            }

            $headers = array('accept' => 'application/octet-stream');

            $url = $this->client->getBaseUrl() . '/' . rawurlencode($this->documentNumber) . '/file';
            $client = clone $this->client;
            $client->setBaseUrl(null);
            $client->setSslVerification(false, false, 0);
            $request = $client->get($url, $headers);
            $tmp_file = 'php://temp/maxmemory:256000';
            $handle = fopen($tmp_file, 'rw');
            $request->setResponseBody($handle);
            $response = $request->send();
            rewind($handle);
            $content = null;
            while (($read = fread($handle, 254)) != null) {
                $content = !isset($content) ? $read : $content . $read;
            }
            fclose($handle);
            return array(
                'content' => $content,
                'length' => $response->getContentLength(),
            );
        }
    }

    /**
     * @param $bill_doc_number
     * @param $developer_id
     * @return array
     *
     * @throws MintApiException
     */
    public function searchBillingDoc($bill_doc_number, $developer_id)
    {

        $docs = array();
        try {
            $url = '/mint/organizations/' . rawurlencode($this->config->orgName) . '/search-billing-documents';

            $devCriteria = new \stdClass();
            $devCriteria->id = $developer_id;
            $devCriteria->orgId = $this->config->orgName;
            $mintCriteria = array(
                'devCriteria' => array($devCriteria,),
                'documentNumber' => $bill_doc_number
            );
            $this->setBaseUrl($url);
            $this->post(null, $mintCriteria);
            $this->restoreBaseUrl();
            $response = $this->responseObj;

            foreach ($response[$this->wrapper_tag] as $doc) {
                $bill_doc = new BillingDocument($this->config);
                $bill_doc->loadFromRawData($doc);
                $docs[] = $bill_doc;
            }
            //return $this->responseObj;
        } catch (ResponseException $re) {
            if (MintApiException::isMintExceptionCode($re)) {
                throw new MintApiException($re);
            }
        }
        return $docs;
    }

    protected function setFile($file)
    {
        $this->file = $file;
    }

    public function getFileMimeType()
    {
        if (!isset($this->fileMimeType)) {
            $this->getFile();
        }
        return $this->fileMimeType;
    }

    protected function setFileMimeType($file_mime_type)
    {
        $this->fileMimeType = $file_mime_type;
    }

    public function getOrganization()
    {
        return $this->organization;
    }

    public function setOrganization(Organization $org)
    {
        $this->organization = $org;
    }

    public function getProducts()
    {
        return $this->product;
    }

    public function addProduct(Product $product)
    {
        $this->product[] = $product;
    }

    public function clearProducts()
    {
        $this->product = array();
    }

    public function getSubOrgs()
    {
        return $this->subOrg;
    }

    public function addSubOrg(Organization $org)
    {
        $this->subOrg[] = $org;
    }

    public function clearSubOrgs()
    {
        $this->subOrg = array();
    }

    public function getDevelopers()
    {
        return $this->developer;
    }

    public function addDeveloper(Developer $developer)
    {
        $this->developer[] = $developer;
    }

    public function clearDevelopers()
    {
        $this->developer = array();
    }

    public function getBillableDeveloper()
    {
        return $this->billableDeveloper;
    }

    public function setBillableDeveloper(Developer $developer)
    {
        $this->billableDeveloper = $developer;
    }

    public function getBillableExchangeOrg()
    {
        return $this->billableExchangeOrg;
    }

    public function setBillableExchangeOrg(Organization $org)
    {
        $this->billableExchangeOrg = $org;
    }

    public function getStartDate()
    {
        return $this->startDate;
    }

    public function setStartDate($start_date)
    {
        $this->startDate = $start_date;
    }

    public function getEndDate()
    {
        return $this->endDate;
    }

    public function setEndDate($end_date)
    {
        $this->endDate = $end_date;
    }

    public function getBillingMonth()
    {
        return $this->billingMonth;
    }

    public function setBillingMonth($month)
    {
        $this->billingMonth = MonthType::get($month);
    }

    public function getBillingYear()
    {
        return $this->billingYear;
    }

    public function setBillingYear($year)
    {
        $this->billingYear = $year;
    }

    public function getStatus()
    {
        return $this->status;
    }

    public function setStatus($status)
    {
        $this->status = $status;
    }

    public function getType()
    {
        return $this->type;
    }

    public function setType($type)
    {
        $this->type = $type;
    }

    public function getDocumentNumber()
    {
        return $this->documentNumber;
    }

    public function setDocumentNumber($document_number)
    {
        $this->documentNumber = $document_number;
    }

    public function getCurrency()
    {
        return $this->currency;
    }

    public function setCurrency($currency)
    {
        $this->currency = $currency;
    }

    public function getAmount()
    {
        return $this->amount;
    }

    public function setAmount($amount)
    {
        $this->amount = $amount;
    }

    public function getTaxAmount()
    {
        return $this->taxAmount;
    }

    public function setTaxAmount($tax_amount)
    {
        $this->tax_amount = $tax_amount;
    }

    public function getDueDate()
    {
        return $this->dueDate;
    }

    public function setDueDate($due_date)
    {
        $this->due_date = $due_date;
    }

    public function getBatchId()
    {
        return $this->batchId;
    }

    public function setBatchId($batch_id)
    {
        $this->batchId = $batch_id;
    }

    public function getPaymentDueDays()
    {
        return $this->paymentDueDays;
    }

    public function setPaymentDueDays($due_days)
    {
        $this->paymentDueDays = $due_days;
    }

    public function getBillingDocDate()
    {
        return $this->billingDocDate;
    }

    public function setBillingDocDate($date)
    {
        $this->billingDocDate = $date;
    }
}