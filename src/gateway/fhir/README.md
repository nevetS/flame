Overview
--------
API proxies implementing all FHIR operations against the following Project Argonaut FHIR resources:
a.	Patient
b.	Encounter
c.	Observation
d.	Condition
e.	MedicationPrescription
f.	MedicationDispense
g.	MedicationAdministration
h.	MedicationStatement
i.	Immunization
j.	AllergyIntolerance
k.	DiagnosticOrder
l.	DiagnosticReport
m.	CarePlan
n.	Procedure
o.	Practitioner
p.	DocumentReference

Each FHIR API consists of  two parts. External API and Internal or Connector APIs.
External APIs represent the FHIR resources and are exposed for the developers. Each External FHIR API has one or more Connectors.
External API are named as [FHIR Resource name]_FHIR_API.
Connector can eb identified as [FHIR Resource name]_Connector-API-[Taget Server name]-[DSTU1 or DSTU2] 
e.g. AllergyIntolerance-Connector-API-HAPI-DSTU2
where 
Resource name is AllergyIntolerance
Target Server name used is HAPI server

-----------------------------------------------------
Deploying FHIR APIs
-----------------------------------------------------
Prerequisites:
You need to have access to deployed Apigee Edge Services with organization details. If you don’t have this – please sign-up at [Apigee Edge](http://enterprise.apigee.com) now.
[Maven](http://maven.apache.org) is used for managing the dependencies and for build automation. Get it installed beforehand.

Go to each API directory path and run following command: mvn clean install -Dusername={email} -Dpassword={password} -Dorg={org} -Ptest
For e.g. to deploy Patient_FHIR_API, go to flame\src\gateway\fhir\Patient-FHIR-API and run following command
mvn clean install -Dusername={email} -Dpassword={password} -Dorg={org} -Ptest

To deploy Patient_FHIR_API, go to flame\src\gateway\fhir\Patient-FHIR-API and run following command
mvn clean install -Dusername={email} -Dpassword={password} -Dorg={org} -Ptest

Similarly to deploy Patient Connector proxy go to flame\src\gateway\fhir\Connector-API-HAPI-DSTU2\Patient-Connector-API-HAPI-DSTU2, and
un the same command.
mvn clean install -Dusername={email} -Dpassword={password} -Dorg={org} -Ptest
