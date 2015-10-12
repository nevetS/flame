Overview
--------
The identity and ouath solution for FHIR APIs is built upon [Grass] which is an **identity solution** based on Apigee Edge platform. 

For more details on Grass Architecture and API Specification, please refer https://github.com/apigee/grass#grass-definition

-----------------------------------------------------
Deploying and using Grass Identity Solution for FHIR
-----------------------------------------------------
Prerequisites:
You need to have access to deployed Apigee Edge Services with organization details. If you don’t have this – please sign-up at [Apigee Edge](http://enterprise.apigee.com) now.
[Maven](http://maven.apache.org) is used for managing the dependencies and for build automation. Get it installed beforehand.

    Git clone “grass” repo.
    Goto /flame/src/gateway/identityandoauth/setup-identity. 
    Run setup.sh

* When you run the setup.sh script it will ask for your organization name on Apigee Edge, the environment to setup the Identity solution and the Apigee Edge credentials.	
* It then creates API service resources (cache resources) ,  a developer (Identity User),  product (Identity App product) and an app (Identity App) for the created developer. 
* Then it will ask for the name of the App Services organization (An app services organization will be created by default when you create an organization on Apigee Edge. So the same can be used.) 
  and the name for the App to be created on App services. 
* Post this, the App services will be setup along with 2 custom collections, Consent & SSO (Single Sign-On). 
* In the end it deploys the Identity API Proxies to your specified organization and deploys to the environment you specified.

###### Please Note: 
The setup.sh needs to be executed from setup-identity folder. It would fail otherwise since relative paths are used from the setup-identity folder. Please feel free to contribute to the setup script itself and make it robust.
