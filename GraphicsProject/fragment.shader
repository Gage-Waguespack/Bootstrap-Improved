#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 iDirection;
uniform vec3 iAmbient;
uniform vec3 iDiffuse;
uniform vec3 iSpecular;

uniform vec3 iDirectionF;
uniform vec3 iAmbientF;
uniform vec3 iDiffuseF;
uniform vec3 iSpecularF;

uniform vec3 cameraPosition;

out vec4 pColor;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection);
	vec3 iNormalF = normalize(iDirection);

	//Light
	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular * specularTerm;

	vec4 lColor = vec4(ambientColor + diffuseColor + specularColor, 1.0f);

	//Flashlight
	//Calculate ambient color
	vec3 ambientColorF = (fColor.xyz + kAmbient) * iAmbientF;

	//Calculate diffuse color
	float lambertTermF = dot(kNormal, -iNormalF);
	lambertTermF = max(0.0f, min(1.0f, lambertTermF));
	vec3 diffuseColorF = (fColor.xyz + kDiffuse) * iDiffuseF * lambertTermF;

	//Calculate specular color
	vec3 surfaceToViewF = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormalF = reflect(iNormal, kNormal);
	float specularTermF = dot(surfaceToViewF, reflectionNormalF);
	specularTermF = max(0.0f, specularTermF);
	specularTermF = pow(specularTermF, kSpecularPower);
	vec3 specularColorF = (fColor.xyz + kSpecular) * iSpecularF * specularTermF;

	vec4 fColor = vec4(ambientColorF + diffuseColorF + specularColorF, 1.0f);

	pColor = lColor + fColor;
}
