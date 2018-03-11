var usrnb =0;
do  usrnb=prompt('Veuillez saisir un nombre entre 0 et 999'); while(isNaN(usrnb|| usrnb <0 || 999 < usrnb));
var unit =0;
var decade=0, hundred=0;

function decompose(numbertodecompose)
{
   unit = numbertodecompose % 10;
   if (numbertodecompose > 100)
   {
   	  decade = ((numbertodecompose - unit )%100)/10 ;
      hundred =  (numbertodecompose -((decade*10)+unit))/100;
   }
   else 
   	{
   		decade =  (numbertodecompose-unit)/10;
   	}

 alert('unite : ' + unit + ' dizaine : ' + decade + ' centaine : '+ hundred );
}

var digit=['un','deux','trois','quatre', 'cinq', 'six', 'sept','huit', 'neuf'];
var dizaine=['dix', 'vingt', 'trente','quarante', 'cinquante','soixante'];
var special=['onze', 'douze','treize','quartoze', 'quinze','seize','dix-sept', 'dix-huit','dix-neuf'];

function converter(unit, decade, hundred)
{
   var numberconverted; 
   if (usrnb > 100)
   {
   	  if (hundred)
      {
      	//alert(hundred);
     	if (hundred === 1) numberconverted = 'cent';
   	    else numberconverted = digit[hundred-1] + ' cent';
      }

      if (decade)
      {
      	if (decade === 7) numberconverted +=' '+dizaine[5]+'-';
      	if (decade === 8 || decade === 9) numberconverted +=' '+digit[3]+'-'+dizaine[1]+'-';
      	else numberconverted +=' '+dizaine[decade-1];
      	alert(numberconverted);
      }
      if (unit)
      {
      	if (decade === 7 || decade === 8 || decade === 9) numberconverted +=' '+special[unit-1];
      	else numberconverted +=' '+digit[unit-1];
      	a
      }
   }
   else if (usrnb >10 && usrnb <100)
   {
   	   if (decade)
      {
      	if (decade === 1) ;
      	if (decade === 7) numberconverted = dizaine[5] +'-';
      	if (decade === 8 || decade === 9) numberconverted =  digit[3]+'-'+dizaine[1]+'-';
      	else numberconverted = dizaine[decade-1];
      }
      if (unit)
      {
      	if (decade === 7 || decade === 8 || decade === 9 || decade === 1) numberconverted +=' '+special[unit-1];
      	else numberconverted +=' '+digit[unit-1];
      }
   }
   else numberconverted = digit[unit -1];

     return numberconverted;
}

decompose(usrnb);

var toshow = converter(unit, decade, hundred);

alert(toshow);
