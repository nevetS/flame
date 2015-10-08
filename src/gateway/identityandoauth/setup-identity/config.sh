apikey="4ynh0bmasEuI8Z9gtCfOShgTAyYbz3SY"
apisecret="IRtZphns07G6Jvr3"
auth=`echo ${apikey}:${apisecret} | base64`
org=fhirsandbox
env=prod
host=$org-$env.apigee.net
appkey="YXA6fVpkIGjqEeWkPQkU13Nxhw"
appsecret="YXA6dLUr9i-2yiRUa1ZmpvVZ0fQ_fC0"
apporg=clinic
appapp=consentm

#identity-consent-app config.json 

sed -i  "s/__APIKEY__/$apikey/g" ../identity-consent-app/config.json
sed -i  "s/__AUTH__/$auth/g" ../identity-consent-app/config.json
sed -i  "s/__HOST__/$host/g" ../identity-consent-app/config.json

#identity-consentmgmt-api config.json
sed -i  "s/__APPKEY__/$appkey/g" ../identity-consentmgmt-api/config.json
sed -i  "s/__APPSECRET__/$appsecret/g" ../identity-consentmgmt-api/config.json
sed -i  "s/__APPORG__/$apporg/g" ../identity-consentmgmt-api/config.json
sed -i  "s/__APPAPP__/$appapp/g" ../identity-consentmgmt-api/config.json

#identity-consentmgmt-api package.json
sed -i  "s/__APPORG__/$apporg/g" ../identity-consentmgmt-api-node-module/consentmgmt/package.json
sed -i  "s/__APPAPP__/$appapp/g" ../identity-consentmgmt-api-node-module/consentmgmt/package.json
sed -i  "s/__APPKEY__/$appkey/g" ../identity-consentmgmt-api-node-module/consentmgmt/package.json
sed -i  "s/__APPSECRET__/$appsecret/g" ../identity-consentmgmt-api-node-module/consentmgmt/package.json

#identity-oauthv2-api config.json
sed -i  "s/__HOST__/$host/g" ../identity-oauthv2-api/config.json
sed -i  "s/__AUTH__/$auth/g" ../identity-oauthv2-api/config.json

#identity-usermgmt-api config.json
sed -i  "s/__APPORG__/$apporg/g" ../identity-usermgmt-api/config.json
sed -i  "s/__APPAPP__/$appapp/g" ../identity-usermgmt-api/config.json
sed -i  "s/__APPKEY__/$appkey/g" ../identity-usermgmt-api/config.json
sed -i  "s/__APPSECRET__/$appsecret/g" ../identity-usermgmt-api/config.json

#identity-usermgmt-api package.json
sed -i  "s/__APPORG__/$apporg/g" ../identity-usermgmt-node-module/usermgmt/package.json
sed -i  "s/__APPAPP__/$appapp/g" ../identity-usermgmt-node-module/usermgmt/package.json
sed -i  "s/__APPKEY__/$appkey/g" ../identity-usermgmt-node-module/usermgmt/package.json
sed -i  "s/__APPSECRET__/$appsecret/g" ../identity-usermgmt-node-module/usermgmt/package.json

#identity-demo-api config.json
sed -i  "s/__HOST__/$host/g" ../identity-demo-app/config.json
sed -i  "s/__APIKEY__/$apikey/g" ../identity-demo-app/config.json
sed -i  "s/__APISECRET__/$apisecret/g" ../identity-demo-app/config.json

