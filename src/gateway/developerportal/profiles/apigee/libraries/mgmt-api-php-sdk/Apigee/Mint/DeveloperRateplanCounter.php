<?php
namespace Apigee\Mint;

class DeveloperRateplanCounter extends Base\BaseObject
{

    private $id;

    public function __construct(\Apigee\Util\OrgConfig $config)
    {
        $base_url = '/mint/organizations/' . rawurlencode($config->orgName) . '/developer-ratecard-counters';
        $this->init($config, $base_url);

        $this->wrapperTag = 'developerRateCardCounter';
        // TODO: verify the following two items when docs are fleshed out
        $this->idField = 'id';
        $this->idIsAutogenerated = true;

        $this->initValues();
    }

    protected function initValues()
    {
        // TODO
    }

    public function instantiateNew()
    {
        return new DeveloperRateplanCounter($this->config);
    }

    public function loadFromRawData($data, $reset = false)
    {
        if ($reset) {
            $this->initValues();
        }
        $excluded_properties = array();
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

    private function setId($id)
    {
        $this->id = $id;
    }
}
