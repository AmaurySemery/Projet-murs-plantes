m = parseInt(msg.moyenne);
Niveau = parseInt(msg.req.params.pourcentage);
Api = parseInt(msg.total);
ApiSup = true;
ApiInf = false;

if (parseInt(m) <=30){msg.payload="100"}
// Si le mur passe le seuil de stress hydrique, activation forcée de la pompe
if (parseInt(Api) >= 20){Api = ApiSup}
// Si Api >= 20 mm de pluie => Api équivaut à "true"
if (parseInt(Api) !== 0 && parseInt(Api) < 20){Api = ApiInf}
// Si Api différent de 0 et inférieur à 20 => Api équivaut à "false"
if (parseInt(Niveau) <=30 && parseInt(Api) < 20){msg.payload="30"}
// Si Niveau inférieur ou égal à 30 et Api inférieur à 20 mm de pluie => mode éco
if (parseInt(Api) === 0){msg.payload="30"}
// Si Api est égal à 0 mm de pluie, mode éco
if (parseInt(Niveau) >= 70 && Api !== 0){msg.payload="70"}
// Si Niveau supérieur ou égal à 70 et Api différent de 0 mm de pluie, mode intensif
if (Api == ApiSup){msg.payload="70"}
// Si Api supérieur à 20 mm de pluie, mode intensif
//if (parseInt(m) >= 70){msg.payload="90"}
// Cette dernière ligne peut être utilisée si on veut intégrer un seuil max d'humidité à la plante pour cesser l'arrosage
else {msg.payload="50"}
// Autrement, mode normal
return msg;

// Intégrer un mode où le système se bloque en cas de gel
