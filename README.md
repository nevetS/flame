<p align="left"><a href="http://apigee.com/"><img src="http://apigee.com/about/sites/all/themes/apigee_themes/apigee_mktg/images/logo.png"/></a></p>

Overview
--------
[Flame](https://github.com/apigee/flame#Flame-definition) is a Health care API Exposure solution based on Apigee Edge platform. API Exposure is the essential block of any digital ecosystem needs, let it be application, data analysis and contextual content delivery through APIs. 

The key differences between flame and any traditional API Exposure solutions

    * FHIR DSTU 2 API Compliant convering all 16 FHIR resources
    * Complete OAUTH 2.0 support for B2B and B2C scenarios
    * Developer Portal with API Documentation and Sandbox 
    * It has in-built consent and identity management. Additionally pluggable to any identity system.
    * OOTB API Analytics

The Health API solution is built based upon the FHIR API Specification [https://www.hl7.org/fhir/index.html]


Contents
----------------------------------

#### Apps
   * Consent App
     * Consent Managment solution on Apigee Edge. 
 
#### API's
   * Internal
     * Identity-Authentication-spi
        * Wrapper for Thrid party Identity service provider interface. 
       * Identity-sms-token-api
        * Provide SMS token capabilities for Strong authentication
     * FHIR Connector APIs(named based on FHIR Resource)
        * Used for connecting with various  health care backends.
         
   * External
     * FHIR Exposure APIs(named based on FHIR Reasources)
     * Identity-Consentmgmt-api
        * Provides Consent Management support on Apigee Edge. 
        * Uses App Services to store consent. Custom collections - consent, sso
      * Identiy-Usermgmt-api
        * The identity provider API. 
        * Uses App Services as the User store. Default collection - user
      * Identity-oauthv2-api
        * The key OAUTH API based upon the OAUTH 2.0 spec.
        * Presently supports  the authorization code and Client credential flow. 
             
See [http://apigee.com/docs/api-services/content/deploying-proxies-ui] for API proxy bundle deployments

#### Developer Portal
    * Apigee Edge - Developer Portal with Health care theme
    * FHIR API Documentation and Sandbox for easy understanding
    * App Gallery to promote App ecosystem of your API program
See [http://apigee.com/docs/developer-services/content/what-developer-portal] for Apigee Developer Portal customisation

Make your contributions to Flame
--------------------------------
You can make your valuable contributions to the open source project Flame. You can see the contribution guidlines and documenation at [Contribute to Flame](https://github.com/apigee/flame/blob/master/CONTRIBUTING.md).

