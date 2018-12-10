#include "juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Participantes .h"
#include "Temporizador.h"
#include "Niveles.h"
using namespace sf;
using namespace std;
int juego::aleatorio(int numero){
    srand(time(NULL));
    return (rand()%numero)+1;
    Sleep(5000);
}
juego::juego(int resolucion_x, int resolucion_y, string titulo)
{
    fps=60;
    ventana= new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);

    ventana->setFramerateLimit(fps);
    //personas
    int numPersonasrul3=3;
    string Personas3[numPersonasrul3];
    Personas3[0]="Jugador1";
    Personas3[1]="Jugador2";
    Personas3[2]="Jugador3";

   /* srand(time(NULL));
    int aleajugs3= (rand()%numPersonasrul3)+1;*/
    int aleajugs3= aleatorio(numPersonasrul3);

    int numPersonasrul4=4;
    string Personas4[numPersonasrul4];
    Personas4[0]="Jugador1";
    Personas4[1]="Jugador2";
    Personas4[2]="Jugador3";
    Personas4[3]="Jugador4";

   /* srand(time(NULL));
    int aleajugs4= (rand()%numPersonasrul4)+1;*/
    int aleajugs4=aleatorio(numPersonasrul4);

    int numPersonasrul5=5;
    string Personas5[numPersonasrul5];
    Personas5[0]="Jugador1";
    Personas5[1]="Jugador2";
    Personas5[2]="Jugador3";
    Personas5[3]="Jugador4";
    Personas5[4]="Jugador5";

    /*srand(time(NULL));
    int aleajugs5= (rand()%numPersonasrul5)+1;*/
    int aleajugs5=aleatorio(numPersonasrul5);

    //verdades
    int numPreguntas=236;
    string Preguntas[numPreguntas];
    Preguntas[0]="�Qu� es lo m�s extra�o que has buscado en internet?";
    Preguntas[1]="�Cu�l es la cosa m�s infantil que todav�a haces?";
    Preguntas[2]="�Qu� no has contado nunca a nadie?";
    Preguntas[3]="Si tuvieras un control remoto que funciona sobre cualquier cosa, �qu� controlar�a?";
    Preguntas[4]="�Cu�l es el h�bito m�s repugnante que tienes?";
    Preguntas[5]="�Qu� quieres que tus padres nunca sepan?";
    Preguntas[6]="�A qui�n salvar�as si viene un meteorito y solo puedes salvar a una persona?";
    Preguntas[7]="�Cu�l es tu estrategia para conquistar a una mujer/hombre?";
    Preguntas[8]="�Qu� es lo m�s loco que has hecho sin que tus padres lo sepan?";
    Preguntas[9]="�Qu� har�as si tus padres te dejaran en casa durante una semana entera?";
    Preguntas[10]="�Alguna vez te gust� uno de tus profesores en la escuela?";
    Preguntas[11]="�Cu�l es la foto m�s vergonzosa de ti?";
    Preguntas[12]="�Cu�l es la cosa m�s cara que has robado?";
    Preguntas[13]="�Qu� cosa mala has hecho que nadie descubri�?";
    Preguntas[14]="�Has sido alguna vez infiel? �Te han sido alguna vez infiel?";
    Preguntas[15]="�Cu�l es la cosa m�s tonta a la que tienes un apego emocional?";
    Preguntas[16]="�Cu�l es tu miedo m�s oscuro?";
    Preguntas[17]="�Alguna vez has mentido acerca de estar enfermo para que puedas quedarte en casa y no ir al trabajo o a la escuela?";
    Preguntas[18]="�Cu�l es el lugar m�s extra�o en el que has orinado?";
    Preguntas[19]="�Alguna vez te has hecho caca en los pantalones desde que eras un ni�o?";
    Preguntas[20]="�Qui�n tiene el mejor trasero de todos los que estamos aqu�?";
    Preguntas[21]="�Cu�ndo fue la �ltima vez que te orinaste en la cama?";
    Preguntas[22]="Si pudieras volver a hacer una cosa que hiciste cuando eras un ni�o, �cu�l ser�a?";
    Preguntas[23]="�Cu�l es la cosa m�s grosera que ha salido de tu cuerpo?";
    Preguntas[24]="�Alguna vez te has tirado un pedo fuerte en clase?";
    Preguntas[25]="�Con qu� frecuencia lavas tu ropa interior?";
    Preguntas[26]="�Alguna vez has probado la cera del o�do?";
    Preguntas[27]="�Alguna vez le enviaste un texto inapropiado a tu mam� o pap� por accidente?";
    Preguntas[28]="�Has llegado a olfatear tu ropa interior para saber si est� limpia?";
    Preguntas[29]="�Qu� es lo m�s desagradable que has hecho en lugar p�blico?";
    Preguntas[30]="�Cu�l de los jugadores de este grupo tiene una boca m�s sensual?";
    Preguntas[31]="�Cu�l es la parte del cuerpo que encuentra m�s atractiva en una persona del otro (o mismo) g�nero?";
    Preguntas[32]="�Cu�l de las personas dentro de este grupo crees que ha mejorado su apariencia f�sica?";
    Preguntas[33]="�Crees que alguna de las personas que se encuentran aqu� tiene una pareja que no le conviene? �Qui�n? �Por qu�?";
    Preguntas[34]="�Qu� har�as si supieras que el mundo acabar� ma�ana?";
    Preguntas[35]="�Qu� has hecho alguna vez y no has contado a nadie?";
    Preguntas[36]="�Cu�ndo fue la �ltima vez que cantaste y bailaste solo?";
    Preguntas[37]="�Qui�n tiene los ojos m�s hermosos de todas las personas presentes?";
    Preguntas[38]="�Con qui�n saldr�as de aqu� en una cita?";
    Preguntas[39]="�A qu� persona famosa besar�as?";
    Preguntas[40]="�A qui�n llevar�as contigo si te quedar�s naufrago durante 3 d�as en una isla?";
    Preguntas[41]="�Qu� har�as si fueras invisible por un d�a?";
    Preguntas[42]="�Cu�nto es el tiempo m�ximo que has pasado sin darte un ba�o?";
    Preguntas[43]="�Qui�n es la persona que m�s sabe de ti y qu� tipo de secretos sobre tu vida guarda?";
    Preguntas[44]="�De qu� color es tu ropa interior?";
    Preguntas[45]="�Alguna vez has orinado en una piscina?";
    Preguntas[46]="�Cu�l es el lugar m�s extra�o en el que has tenido que ir al ba�o?";
    Preguntas[47]="�Cu�l es tu talento m�s extra�o?";
    Preguntas[48]="�Alguna vez besaste a alguien de tu mismo sexo?";
    Preguntas[49]="�Cu�l es la mentira m�s tonta que le has dicho o alguna vez le dijiste a alguien?";
    Preguntas[50]="�C�mo ser�a tu primera cita perfecta?";
    Preguntas[51]="�Cu�l crees que es la parte m�s atractiva de tu cuerpo?";
    Preguntas[52]="�Qu� es lo primero que le miras a una mujer o un hombre cuando lo conoces?";
    Preguntas[53]="�Alguna vez hiciste trampa en la escuela para pasar un examen?";
    Preguntas[54]="�C�mo fue tu primer beso?";
    Preguntas[55]="�Qu� estar�as dispuesto a hacer por un mill�n de d�lares?";
    Preguntas[56]="�Te has enamorado de alguien alguna vez y no se lo has contado?";
    Preguntas[57]="�Cu�l es tu fantas�a m�s deseada?";
    Preguntas[58]="�Cu�l fue el encuentro rom�ntico m�s inc�modo que tuviste?";
    Preguntas[59]="�Has hecho cosas borracho que al d�a siguiente no recuerdes?";
    Preguntas[60]="�Qu� es lo m�s loco que has hecho mientras estabas borracho?";
    Preguntas[61]="�Cu�l fue el momento m�s embarazoso de tu vida?";
    Preguntas[62]="�C�mo fue el sue�o m�s raro que has tenido?";
    Preguntas[63]="�Cu�l es la cosa m�s embarazosa que tus padres te han pillado haciendo?";
    Preguntas[64]="�Qui�n es la persona m�s sexy aqu�?";
    Preguntas[65]="�Qu� secreto de ti mismo le dijiste a alguien en confianza y luego ese secreto fue divulgado a muchas otras personas?";
    Preguntas[66]="�Por qu� rompiste con tu �ltimo novio o novia?";
    Preguntas[67]="�En qu� pa�s te gustar�a vivir si tuvieras la oportunidad?";
    Preguntas[68]="�Cu�l es la comida m�s ex�tica que has comido?";
    Preguntas[69]="�C�mo ser�a la boda de tus sue�os?";
    Preguntas[70]="�Qu� te gustar�a cambiar de tu cuerpo?";
    Preguntas[71]="�Qui�n es tu persona favorita y por qu�?";
    Preguntas[72]="�Alguna vez has contado una mentira durante un juego de verdad o reto? �Qu� fue y por qu�?";
    Preguntas[73]="�Cu�l es tu mayor miedo?";
    Preguntas[74]="�Qu� pas� en el peor d�a de tu vida?";
    Preguntas[75]="�Cu�l ser�a tu poder si pudieras ser un superh�rore?";
    Preguntas[76]="�Qu� pel�cula elegir�as si pudieras convertirla en tu vida?";
    Preguntas[77]="�Cu�l es tu talento especial?";
    Preguntas[78]="�Cu�l es la mejor comida que has probado?";
    Preguntas[79]="�Cu�l es tu pel�cula favorita de Disney y por qu�?";
    Preguntas[80]="�Qu� har�as con un mill�n de d�lares si alguna vez ganaras la loter�a?";
    Preguntas[81]="Danos una lista de 10 art�culos o cosas que compraste y nunca utilizaste o lamentaste comprar";
    Preguntas[82]="�Cu�l ha sido tu mayor humillaci�n?";
    Preguntas[83]="�Cu�l es tu cualidad personal o caracter�stica que te gustar�a cambiar?";
    Preguntas[84]="�Qu� es lo m�s loco que te ha pasado en un centro comercial?";
    Preguntas[85]="�Qu� es lo peor que has hecho en tu vida?";
    Preguntas[86]="�Alguna vez pensaste en enga�ar a tu novio / novia?";
    Preguntas[87]="�Alguna vez has mentido a tu pareja para evitar un momento �ntimo, por ejemplo, decir que te duele la cabeza?";
    Preguntas[88]="�Cu�l es la broma m�s cruel que le has gastado a alguien?";
    Preguntas[89]="�Cu�l es la cosa m�s embarazosa que has puesto en las redes sociales?";
    Preguntas[90]="�Cu�l es la peor mentira que le has dicho a tus padres?";
    Preguntas[91]="�En qu� pelea que has tenido has ganado? �Y perdido?";
    Preguntas[92]="�Cu�l es la cosa que m�s te molesta que hace tu mam�?";
    Preguntas[93]="�Cu�l es la cosa que m�s te molesta de tu papa?";
    Preguntas[94]="�Cu�l es la historia m�s divertida que tus abuelos te han contado?";
    Preguntas[95]="�Cu�l era tu canci�n favorita en tu infancia?";
    Preguntas[96]="�C�mo es la casa de tus sue�os?";
    Preguntas[97]="�Cu�l es el periodo m�s largo que has pasado sin ba�arte y por qu�?";
    Preguntas[98]="�Has llevado la misma ropa por m�s de 3 d�as?";
    Preguntas[99]="�Qu� animal ser�as?";
    Preguntas[100]="�Qu� dinosaurio ser�as?";
    Preguntas[101]="�Qu� supervillano ser�as?";
    Preguntas[102]="�Con qu� celebridad est�s obsesionado?";
    Preguntas[103]="�Cu�l es el video YouTube m�s divertido que has visto?";
    Preguntas[104]="�Qui�n es el peor maestro que has tenido y por qu�?";
    Preguntas[105]="�Cu�l es tu equipo deportivo favorito?";
    Preguntas[106]="�Cu�l es tu canci�n favorita en este momento?";
    Preguntas[107]="�Podr�as pasar dos meses sin hablar con tus amigos?";
    Preguntas[108]="�Podr�as pasar dos meses sin tu tel�fono?";
    Preguntas[109]="�Podr�as pasar dos meses sin ver televisi�n?";
    Preguntas[110]="�Podr�as pasar dos meses sin conectarte a las redes sociales?";
    Preguntas[111]="�Qu� prejuicio albergas secretamente?";
    Preguntas[112]="�Cu�ntos a�os ten�as cuando diste tu primer beso?";
    Preguntas[113]="�Qu� har�as si tu novio o novia acabara con su relaci�n en este momento?";
    Preguntas[114]="�Si pudieras salir con alg�n famoso con qui�n ser�a?";
    Preguntas[115]="�Qu� es lo m�s gracioso que te ha sucedido durante una cita rom�ntica?";
    Preguntas[116]="�Qu� har�as si te encontraras mucho dinero en la calle?";
    Preguntas[117]="�Cu�l fue tu primera impresi�n de tu novia o novio cuando se conocieron?";
    Preguntas[118]="�Si tuvieras que casarte con alguien que no te gusta, con qui�n te casar�as?";
    Preguntas[119]="Si te encontraras en una isla desierta y tuvieras que elegir a un amigo para que te hiciera compa��a, �a qui�n elegir�as?";
    Preguntas[120]="�Alguna vez un amigo ha coqueteado con tu pareja?";
    Preguntas[121]="�En qu� condiciones le mentir�as a un amigo?";
    Preguntas[122]="�Cu�l creer�as que puede ser una pregunta bastante inc�moda?";
    Preguntas[123]="�Alguna vez has robado algo? �Qu� robaste y por qu� lo hiciste?";
    Preguntas[124]="�Qu� es lo m�s est�pido que has hecho en tu vida?";
    Preguntas[125]="�Si no estuvieras aqu�, que estar�as haciendo en este momento?";
    Preguntas[126]="�Qu� es lo m�s vergonzoso que te ha sucedido estando desnudo?";
    Preguntas[127]="�Si pudieras hacer lo que quisieras, cu�l ser�a tu trabajo so�ado?";
    Preguntas[128]="�Qu� quieres hacer durante los pr�ximos a�os?";
    Preguntas[129]="Si pudieras ser otra persona, �qui�n ser�as?";
    Preguntas[130]="�Qu� te gustar�a inventar?";
    Preguntas[131]="Si pudieras nacer de nuevo, �d�nde te gustar�a nacer? �Qui�n te gustar�a ser?";
    Preguntas[132]="�A qu� le tienes miedo? �Por qu�?";
    Preguntas[133]="�Cu�l recuerdas como el peor d�a de tu vida? �Por qu�?";
    Preguntas[134]="�Alguna vez has actuado como un loco en un lugar p�blico?";
    Preguntas[135]="�Alguna vez has pretendido ser quien no eres para obtener alg�n beneficio?";
    Preguntas[136]="�Qu� har�as si pudieras viajar en el tiempo?";
    Preguntas[137]="�Alguna vez has espiado a alguien?";
    Preguntas[138]="�Qu� es lo que m�s te molesta?";
    Preguntas[139]="�Qu� har�as si ganaras la loter�a?";
    Preguntas[140]="�Qu� es lo m�s malicioso que has hecho en tu vida?";
    Preguntas[141]="�Alguna vez has iniciado un rumor sobre alguien? �De qu� se trataba?";
    Preguntas[142]="�Cu�l ha sido la fiesta m�s salvaje a la que has ido?";
    Preguntas[143]="�Cu�l ha sido la broma m�s desagradable que has hecho en tu vida?";
    Preguntas[144]="�Alguna vez resultaste atractivo para alguien del mismo sexo? �Qu� pas�? �Cu�l fue tu reacci�n?";
    Preguntas[145]="�Cu�l ha sido el piropo m�s extra�o que te han dicho?";
    Preguntas[146]="�Cu�l ha sido el peor rumor que has compartido? (sabiendo que no era cierto)";
    Preguntas[147]="�Cu�l ha sido el evento m�s traum�tico de tu vida?";
    Preguntas[148]="�Qu� es lo m�s est�pido que le ha dicho a su pareja durante un momento �ntimo?";
    Preguntas[149]="�Alguna vez has ocultado algo de tu pareja?";
    Preguntas[150]="�Cu�l ha sido la peor fiesta a la que has ido?";
    Preguntas[151]="�Cu�l ha sido el momento m�s feliz de tu vida?";
    Preguntas[152]="�Alguna vez has actuado como turista para conseguir algo?";
    Preguntas[153]="�Alguna vez has conducido borracho?";
    Preguntas[154]="�Qu� es lo m�s est�pido que has hecho al volante?";
    Preguntas[155]="�Qu� es lo m�s est�pido que le has dicho a una persona que te gusta?";
    Preguntas[156]="�Cu�l es la apuesta m�s est�pida que has hecho?";
    Preguntas[157]="�Alguna vez te has escapado de clase?";
    Preguntas[158]="�Alguna vez le dijiste a alguien que lo amabas, sin de verdad sentirlo?";
    Preguntas[159]="�Alguna vez te han sacado de un bar o una discoteca?";
    Preguntas[160]="�Qui�n fue tu amor de infancia?";
    Preguntas[161]="�Has besado a alguno de tus amigos m�s cercanos? �Qui�n?";
    Preguntas[162]="�Qu� es lo m�s idiota que has hecho por dinero?";
    Preguntas[163]="Si pudieras tener una conversaci�n con alg�n personaje hist�rico, �con qui�n ser�a?";
    Preguntas[164]="�Alguna vez has sostenido una conversaci�n contigo mismo en voz alta?";
    Preguntas[165]="�Te has colado en una fiesta privada?";
    Preguntas[166]="�Alguna vez has mentido para acostarte con alguien?";
    Preguntas[167]="�Has tenido una experiencia cercana a la muerte?";
    Preguntas[168]="�Has quedado en embarazo o has embarazado a alguien?";
    Preguntas[169]="�Has besado a alguien que tenga el doble de tu edad?";
    Preguntas[170]="�Alguna vez has estado esposado? �Por cu�l raz�n?";
    Preguntas[171]="�Alguna vez has enga�ado o has sido enga�ado?";
    Preguntas[172]="�Qui�n fue tu mejor amigo en la infancia?";
    Preguntas[173]="�Qu� piensan la mayor�a de tus amigos de ti que sea verdad y qu� es totalmente falso?";
    Preguntas[174]="Si pudieras ser una celebridad, �qui�n ser�as?";
    Preguntas[175]="�Campo, playa o monta�a?";
    Preguntas[176]="�Has comido animales crudos?";
    Preguntas[177]="�Has hecho bullying?";
    Preguntas[178]="�Te han hecho bullying?";
    Preguntas[179]="�Ser�as capaz de asesinar a alguien?";
    Preguntas[180]="�Cu�l consideras que es tu peor defecto?";
    Preguntas[181]="�Cu�l es el mejor viaje que has hecho?";
    Preguntas[182]="�Cu�l es el mayor riesgo que has tomado?";
    Preguntas[183]="Si pudieras ser un color, �qu� color ser�as?";
    Preguntas[184]="Si pudieras ser un olor, �qu� olor ser�as?";
    Preguntas[185]="�Alguna vez te has hecho pasar por otra persona?";
    Preguntas[186]="�Qu� es lo m�s cursi que le has dicho a alguien?";
    Preguntas[187]="�C�mo te ves de aqu� a 10 a�os?";
    Preguntas[188]="�Qu� prefieres: libros o pel�culas?";
    Preguntas[189]="�Cu�l fue el mayor trauma de tu ni�ez?";
    Preguntas[190]="Al ba�arte, �qu� parte de tu cuerpo enjabonas primero?";
    Preguntas[191]="�Cu�l es la mayor asquerosidad que has hecho?";
    Preguntas[192]="�Qu� es lo mejor que has hecho en tu vida?";
    Preguntas[193]="�Cu�l crees que es tu peor fracaso?";
    Preguntas[194]="�Crees en Dios?";
    Preguntas[195]="�Qu� es lo m�s asqueroso que has bebido?";
    Preguntas[196]="Si pudieras hacer algo peligroso con la seguridad de que no te pasar�a nada malo, �qu� har�as?";
    Preguntas[197]="�Alguna vez has hecho bromas telef�nicas?";
    Preguntas[198]="�Crees en los extraterrestres?";
    Preguntas[199]="�Cu�l juego era tu preferido cuando eras peque�o?";
    Preguntas[200]="�Cu�l es el momento m�s inc�modo que has tenido en tu vida?";
    Preguntas[201]="�Has estado alguna vez muy cerca de la muerte?";
    Preguntas[202]="�Has tenido alg�n accidente automovil�stico?";
    Preguntas[203]="�Cu�l es el peor viaje que has hecho?";
    Preguntas[204]="Si pudieras ser un instrumento musical, �cu�l ser�as?";
    Preguntas[205]="Si pudieras ser un sonido, �cu�l ser�as?";
    Preguntas[206]="�Cu�l es tu palabra favorita?";
    Preguntas[207]="�Cu�l es la palabra que menos te gusta?";
    Preguntas[208]="�Qu� sonido te gusta m�s?";
    Preguntas[209]="�Qu� profesi�n nunca llevar�as a cabo?";
    Preguntas[210]="�Qu� es lo m�s asqueroso que has comido?";
    Preguntas[211]="�Alguna vez has deseado ser alguien m�s?";
    Preguntas[212]="�Cu�l crees que es tu mejor virtud?";
    Preguntas[213]="�Crees en la vida m�s all� de la muerte?";
    Preguntas[214]="�Cu�l es tu color preferido?";
    Preguntas[215]="�Cu�l es tu comida preferida?";
    Preguntas[216]="�En qu� ocasi�n te has sentido inseguro de ti mismo?";
    Preguntas[217]="�Qu� te quita el sue�o?";
    Preguntas[218]="�Qu� te relaja?";
    Preguntas[219]="�Qu� es lo m�s desconsiderado que has hecho?";
    Preguntas[220]="�Qu� es lo que m�s te gusta hacer?";
    Preguntas[221]="Si pudieras ser una flor, �qu� flor ser�as?";
    Preguntas[222]="�Alguna vez has convivido con alguna pareja?";
    Preguntas[223]="�Alguna vez has estado en una relaci�n sin querer estar?";
    Preguntas[224]="�Qu� es lo m�s considerado que has hecho?";
    Preguntas[225]="�A qu� persona odias?";
    Preguntas[226]="�Sabes si alguna persona te odia?";
    Preguntas[227]="�C�mo te describir�as en tres palabras?";
    Preguntas[228]="�Alguna vez te has comido tus propios mocos?";
    Preguntas[229]="�Alguna vez te has sacado los mocos en p�blico?";
    Preguntas[230]="�Alguna vez ha perdido a una mascota?";
    Preguntas[231]="�Ha fallecido alg�n amigo cercano?";
    Preguntas[232]="�Qu� prefieres: fr�o o calor?";
    Preguntas[233]="Si pudieras ser una bebida, �cu�l ser�as?";
    Preguntas[234]="Si pudieras ser una comida, �cu�l ser�as?";
    Preguntas[235]="�Cu�l es tu miedo m�s oscuro?";

    /*srand(time(NULL));

    int aleatoverdad= (rand()%numPreguntas)+1;*/
    int aleatoverdad=aleatorio(numPreguntas);

    int numRetos=36;
    string Retos[numRetos];
    Retos[0]="Gritar en la calle que te has enamorado";
    Retos[1]="Cantar y bailar como loco.Declararte a la persona que te gusta";
    Retos[2]="Llama a alg�n n�mero desconocido y canta feliz cumplea�os";
    Retos[3]="Abrazar a la primera persona que te encuentres en la calle";
    Retos[4]="Subirse a cantar en la barra de un bar";
    Retos[5]="Tomate una foto embarazosa y publ�cala en tus redes sociales";
    Retos[6]="Act�a como un animal (el grupo elige)";
    Retos[7]="Qu�tate los calcetines con los dientes";
    Retos[8]="Da 10 vueltas y trata de caminar en l�nea recta";
    Retos[9]="Elige a tres personas del grupo y que elijan tres ingredientes de la cocina.M�zclalos y t�matelo";
    Retos[10]="No puedes decir malas palabras durante el resto del juego.Baila la macarena";
    Retos[11]="Ponte los zapatos al rev�s y mantenlos as�.Toma una cucharada de picante";
    Retos[12]="Besa la parte de atr�s del cuello de la persona que est� a tu derecha";
    Retos[13]="Dale un serenata a la persona que est� al frente de ti";
    Retos[14]="V�stete con tu camisa al rev�s";
    Retos[15]="Canta cualquier cosa que digas durante el resto del juego";
    Retos[16]="Baila de froma vergonzosa la cancion que el grupo elija";
    Retos[17]="Recrea una escena de una pelicula tonta con tu mejor amigo";
    Retos[18]="Publica en una red social: Amo a [nombre de la persona que m�s odias]";
    Retos[19]="Sube la foto mas vergonzosa de tu galeria a tu red social favorita";
    Retos[20]="T�mate una foto coqueta y m�ndasela a tu pap�, como si fuera un error";
    Retos[21]="Enviarle un texto a tu novio y termina la relaci�n con una falsa excusa";
    Retos[22]="Dale un me gusta a la foto mas antigua de Instagram de la persona que te gusta";
    Retos[23]="M�jate el cabello y canta y baila frente a todos Loca de Shakira";
    Retos[24]="Recibe una cachetada de cada lado de uno de los jugadores";
    Retos[25]="Tomate una foto haciendo muecas y ponla de estado";
    Retos[26]="Haz 20 abdominales seguidos!";
    Retos[27]="Haz 20 sentadillas seguidas!";
    Retos[28]="Haz 20 ranas seguidas!";
    Retos[29]="Haz 20 planchas seguidas!";
    Retos[30]="Ve a la calle y abraza a un poste";
    Retos[31]="Llama a tu ex y decirle que lo/a extra�as";
    Retos[32]="T�mate una foto en la que salgas muy fe@ y env�asela a la persona que te gusta";
    Retos[33]="D�le un priopo al primer extra�o que pase por la calle";
    Retos[34]="Canta a todo pulm�n la canci�n m�s tonta que hayas escuchado";
    Retos[35]="Camina como un ping�ino alrededor de la habitaci�n";

   /* srand(time(NULL));
    int aleatoretos= (rand()%numRetos)+1;*/
    int aleatoretos=aleatorio(numRetos);



    //textos

    fuente1= new Font();
    if (!fuente1->loadFromFile("comic.ttf"))
    {
        cout << "error" << endl;
    }
    fuente1->loadFromFile("comic.ttf");



   jugadores3A.setFont(*fuente1);
    jugadores3A.setString(Personas3[0]);
    jugadores3A.setPosition(100,400);
    jugadores3A.setColor(Color::Transparent);
    jugadores3A.setCharacterSize(20);

    jugadores3B.setFont(*fuente1);
    jugadores3B.setString(Personas3[1]);
    jugadores3B.setPosition(100,400);
    jugadores3B.setColor(Color::Transparent);
    jugadores3B.setCharacterSize(20);

    jugadores3C.setFont(*fuente1);
    jugadores3C.setString(Personas3[2]);
    jugadores3C.setPosition(100,400);
    jugadores3C.setColor(Color::Transparent);
    jugadores3C.setCharacterSize(20);

    Text array3[3]={jugadores3A,jugadores3B,jugadores3C};



    jugadores4.setFont(*fuente1);
    jugadores4.setString(Personas4[aleajugs4]);
    jugadores4.setPosition(100,400);
    jugadores4.setColor(Color::Transparent);
    jugadores4.setCharacterSize(20);


    jugadores5.setFont(*fuente1);
    jugadores5.setString(Personas5[aleajugs5]);
    jugadores5.setPosition(100,400);
    jugadores5.setColor(Color::Transparent);
    jugadores5.setCharacterSize(20);



    verdades.setFont(*fuente1);
    verdades.setString(Preguntas[aleatoverdad]);
    verdades.setPosition(400,450);
    verdades.setColor(Color::Transparent);
    verdades.setCharacterSize(20);
    verdades.setOrigin(verdades.getGlobalBounds().width/2, verdades.getGlobalBounds().height/2);

    retos.setFont(*fuente1);
    retos.setString(Retos[aleatoretos]);
    retos.setPosition(400,450);
    retos.setColor(Color::Transparent);
    retos.setCharacterSize(20);
    retos.setOrigin(retos.getGlobalBounds().width/2, retos.getGlobalBounds().height/2);

    /*
    Text stream;
    stream << "something else" ;
    string string;
    stream >> string;
    verdades.setString(string);
    */

    /*
    txt_verscore.setFont(*fuente1);
    txt_verscore.setString("2. ver score");
    txt_verscore.setPosition(80,380);
    txt_verscore.setColor(Color::White);
*/
    pantallas();

    gameloop();
}

void juego::pantallas()
{
    pantalla1=new Texture;
    spritep1=new Sprite;

    pantalla1->loadFromFile("pantalla1.png");//logo
    spritep1->setTexture(*pantalla1);//logo
    spritep1->setPosition(0,0);

    evento1= new Event;

    pantalla2=new Texture;
    spritep2=new Sprite;

    pantalla2->loadFromFile("pantalla2.png");
    spritep2->setTexture(*pantalla2);
    spritep2->setPosition(0,0);
    spritep2->setColor(Color::Transparent);

    pantalla3=new Texture;
    spritep3= new Sprite;

    pantalla3->loadFromFile("pantalla3.png");
    spritep3->setTexture(*pantalla3);
    spritep3->setPosition(0,0);
    spritep3->setColor(Color::Transparent);

    pantalla4reto=new Texture;
    spritep4reto= new Sprite;

    pantalla4reto->loadFromFile("pantalla4reto.png");
    spritep4reto->setTexture(*pantalla4reto);
    spritep4reto->setPosition(0,0);
    spritep4reto->setColor(Color::Transparent);

    pantalla4verdad=new Texture;
    spritep4verdad= new Sprite;

    pantalla4verdad->loadFromFile("pantalla4verdad.png");
    spritep4verdad->setTexture(*pantalla4verdad);
    spritep4verdad->setPosition(0,0);
    spritep4verdad->setColor(Color::Transparent);

    ruleta3.loadFromFile("rn3.png");
    rul3.setTexture(ruleta3);
    rul3.setPosition(-800,0);

    ruleta4.loadFromFile("rn4.png");
    rul4.setTexture(ruleta4);
    rul4.setPosition(-800,0);

    ruleta5.loadFromFile("rn5.png");
    rul5.setTexture(ruleta5);
    rul5.setPosition(-800,0);

    botella.loadFromFile("botella.png");
    btlla.setTexture(botella);
    btlla.setPosition(-800,0);
    btlla.setOrigin(btlla.getGlobalBounds().width/2, btlla.getGlobalBounds().height/2);



}



void juego::abrirp()
{


    Event event;
        while (ventana->pollEvent(event))
        {
            if (event.type == Event::Closed)
                ventana->close();
        }


    ventana->clear(Color::White);
    ventana->draw(*spritep1);
    ventana->draw(*spritep2);
    ventana->draw(*spritep3);
    ventana->draw(rul3);
    ventana->draw(rul4);
    ventana->draw(rul5);
    ventana->draw(jugadores3A);
    ventana->draw(jugadores3B);
    ventana->draw(jugadores3C);
    ventana->draw(jugadores4);
    ventana->draw(jugadores5);
    ventana->draw(btlla);
    ventana->draw(verdades);
    ventana->draw(retos);
    ventana->draw(*spritep4reto);
    ventana->draw(*spritep4verdad);
    ventana->display();
}

void juego::gameloop()
{

    Event event;
    SoundBuffer buffer;
    if(!buffer.loadFromFile("musicTF.wav"))
    {
        cout << "ERROR" << endl;
    }

    Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    while(ventana->isOpen()){


        procesar_eventos();
        abrirp();

    }
}

void juego::procesar_eventos()
{
    while(ventana->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::KeyPressed:
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Black);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);

                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
            else if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                spritep1->setColor(Color::Black);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num3)||Keyboard::isKeyPressed(Keyboard::Numpad3))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Black);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(280,300);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                array3[aleatorio(2)].setColor(Color::Black);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);
                btlla.setPosition(400,400);


            if (Keyboard::isKeyPressed(Keyboard::V))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Black);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Black);
                retos.setColor(Color::Transparent);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
            else if (Keyboard::isKeyPressed(Keyboard::R))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Black);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Black);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
                       else if (Keyboard::isKeyPressed(Keyboard::C))
            {
                score++;
                int a=score;
                cout<< a<< endl;
              /*spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Black);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(280,300);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                array3[aleatorio(2)].setColor(Color::Black);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);
                btlla.setPosition(400,400);*/
            }


            }
            else if (Keyboard::isKeyPressed(Keyboard::Num4)||Keyboard::isKeyPressed(Keyboard::Numpad4))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Black);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(280,300);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                btlla.setPosition(400,400);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Black);
                jugadores5.setColor(Color::Transparent);


            if (Keyboard::isKeyPressed(Keyboard::V))
            {

                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Black);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Black);
                retos.setColor(Color::Transparent);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
            else if (Keyboard::isKeyPressed(Keyboard::R))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Black);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Black);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
                       else if (Keyboard::isKeyPressed(Keyboard::C))
            {
                score++;
                int a=score;
                cout<< a<< endl;
                /*spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Black);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(280,300);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Black);
                jugadores5.setColor(Color::Transparent);
                btlla.setPosition(400,400);*/
            }

            }
            else if ((Keyboard::isKeyPressed(Keyboard::Num5)) ||(Keyboard::isKeyPressed(Keyboard::Numpad5))|| (Keyboard::isKeyPressed(Keyboard::B)))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Black);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(280,300);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Transparent);
                btlla.setPosition(400,400);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Black);

            if (Keyboard::isKeyPressed(Keyboard::V))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Transparent);
                spritep4verdad->setColor(Color::Black);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Black);
                retos.setColor(Color::Transparent);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }
            else if (Keyboard::isKeyPressed(Keyboard::R))
            {
                spritep1->setColor(Color::Transparent);
                spritep2->setColor(Color::Transparent);
                spritep3->setColor(Color::Transparent);
                spritep4reto->setColor(Color::Black);
                spritep4verdad->setColor(Color::Transparent);
                rul3.setPosition(-800,0);
                rul4.setPosition(-800,0);
                rul5.setPosition(-800,0);
                verdades.setColor(Color::Transparent);
                retos.setColor(Color::Black);
                btlla.setPosition(-800,0);
                array3[aleatorio(2)].setColor(Color::Transparent);
                jugadores4.setColor(Color::Transparent);
                jugadores5.setColor(Color::Transparent);

            }


            }
       else if (Keyboard::isKeyPressed(Keyboard::C))
            {
                score++;
                int a=score;
                cout<< a<< "score"<< endl;
                Niveles <int> R(a);
                int u= R.getNivelcar();
                Temporizador <int> L(u);
                L.alarma();
            }

        }
    }
}
