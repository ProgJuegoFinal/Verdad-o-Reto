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
    Preguntas[0]="¿Qué es lo más extraño que has buscado en internet?";
    Preguntas[1]="¿Cuál es la cosa más infantil que todavía haces?";
    Preguntas[2]="¿Qué no has contado nunca a nadie?";
    Preguntas[3]="Si tuvieras un control remoto que funciona sobre cualquier cosa, ¿qué controlaría?";
    Preguntas[4]="¿Cuál es el hábito más repugnante que tienes?";
    Preguntas[5]="¿Qué quieres que tus padres nunca sepan?";
    Preguntas[6]="¿A quién salvarías si viene un meteorito y solo puedes salvar a una persona?";
    Preguntas[7]="¿Cuál es tu estrategia para conquistar a una mujer/hombre?";
    Preguntas[8]="¿Qué es lo más loco que has hecho sin que tus padres lo sepan?";
    Preguntas[9]="¿Qué harías si tus padres te dejaran en casa durante una semana entera?";
    Preguntas[10]="¿Alguna vez te gustó uno de tus profesores en la escuela?";
    Preguntas[11]="¿Cuál es la foto más vergonzosa de ti?";
    Preguntas[12]="¿Cuál es la cosa más cara que has robado?";
    Preguntas[13]="¿Qué cosa mala has hecho que nadie descubrió?";
    Preguntas[14]="¿Has sido alguna vez infiel? ¿Te han sido alguna vez infiel?";
    Preguntas[15]="¿Cuál es la cosa más tonta a la que tienes un apego emocional?";
    Preguntas[16]="¿Cuál es tu miedo más oscuro?";
    Preguntas[17]="¿Alguna vez has mentido acerca de estar enfermo para que puedas quedarte en casa y no ir al trabajo o a la escuela?";
    Preguntas[18]="¿Cuál es el lugar más extraño en el que has orinado?";
    Preguntas[19]="¿Alguna vez te has hecho caca en los pantalones desde que eras un niño?";
    Preguntas[20]="¿Quién tiene el mejor trasero de todos los que estamos aquí?";
    Preguntas[21]="¿Cuándo fue la última vez que te orinaste en la cama?";
    Preguntas[22]="Si pudieras volver a hacer una cosa que hiciste cuando eras un niño, ¿cuál sería?";
    Preguntas[23]="¿Cuál es la cosa más grosera que ha salido de tu cuerpo?";
    Preguntas[24]="¿Alguna vez te has tirado un pedo fuerte en clase?";
    Preguntas[25]="¿Con qué frecuencia lavas tu ropa interior?";
    Preguntas[26]="¿Alguna vez has probado la cera del oído?";
    Preguntas[27]="¿Alguna vez le enviaste un texto inapropiado a tu mamá o papá por accidente?";
    Preguntas[28]="¿Has llegado a olfatear tu ropa interior para saber si está limpia?";
    Preguntas[29]="¿Qué es lo más desagradable que has hecho en lugar público?";
    Preguntas[30]="¿Cuál de los jugadores de este grupo tiene una boca más sensual?";
    Preguntas[31]="¿Cuál es la parte del cuerpo que encuentra más atractiva en una persona del otro (o mismo) género?";
    Preguntas[32]="¿Cuál de las personas dentro de este grupo crees que ha mejorado su apariencia física?";
    Preguntas[33]="¿Crees que alguna de las personas que se encuentran aquí tiene una pareja que no le conviene? ¿Quién? ¿Por qué?";
    Preguntas[34]="¿Qué harías si supieras que el mundo acabará mañana?";
    Preguntas[35]="¿Qué has hecho alguna vez y no has contado a nadie?";
    Preguntas[36]="¿Cuándo fue la última vez que cantaste y bailaste solo?";
    Preguntas[37]="¿Quién tiene los ojos más hermosos de todas las personas presentes?";
    Preguntas[38]="¿Con quién saldrías de aquí en una cita?";
    Preguntas[39]="¿A qué persona famosa besarías?";
    Preguntas[40]="¿A quién llevarías contigo si te quedarás naufrago durante 3 días en una isla?";
    Preguntas[41]="¿Qué harías si fueras invisible por un día?";
    Preguntas[42]="¿Cuánto es el tiempo máximo que has pasado sin darte un baño?";
    Preguntas[43]="¿Quién es la persona que más sabe de ti y qué tipo de secretos sobre tu vida guarda?";
    Preguntas[44]="¿De qué color es tu ropa interior?";
    Preguntas[45]="¿Alguna vez has orinado en una piscina?";
    Preguntas[46]="¿Cuál es el lugar más extraño en el que has tenido que ir al baño?";
    Preguntas[47]="¿Cuál es tu talento más extraño?";
    Preguntas[48]="¿Alguna vez besaste a alguien de tu mismo sexo?";
    Preguntas[49]="¿Cuál es la mentira más tonta que le has dicho o alguna vez le dijiste a alguien?";
    Preguntas[50]="¿Cómo sería tu primera cita perfecta?";
    Preguntas[51]="¿Cuál crees que es la parte más atractiva de tu cuerpo?";
    Preguntas[52]="¿Qué es lo primero que le miras a una mujer o un hombre cuando lo conoces?";
    Preguntas[53]="¿Alguna vez hiciste trampa en la escuela para pasar un examen?";
    Preguntas[54]="¿Cómo fue tu primer beso?";
    Preguntas[55]="¿Qué estarías dispuesto a hacer por un millón de dólares?";
    Preguntas[56]="¿Te has enamorado de alguien alguna vez y no se lo has contado?";
    Preguntas[57]="¿Cuál es tu fantasía más deseada?";
    Preguntas[58]="¿Cuál fue el encuentro romántico más incómodo que tuviste?";
    Preguntas[59]="¿Has hecho cosas borracho que al día siguiente no recuerdes?";
    Preguntas[60]="¿Qué es lo más loco que has hecho mientras estabas borracho?";
    Preguntas[61]="¿Cuál fue el momento más embarazoso de tu vida?";
    Preguntas[62]="¿Cómo fue el sueño más raro que has tenido?";
    Preguntas[63]="¿Cuál es la cosa más embarazosa que tus padres te han pillado haciendo?";
    Preguntas[64]="¿Quién es la persona más sexy aquí?";
    Preguntas[65]="¿Qué secreto de ti mismo le dijiste a alguien en confianza y luego ese secreto fue divulgado a muchas otras personas?";
    Preguntas[66]="¿Por qué rompiste con tu último novio o novia?";
    Preguntas[67]="¿En qué país te gustaría vivir si tuvieras la oportunidad?";
    Preguntas[68]="¿Cuál es la comida más exótica que has comido?";
    Preguntas[69]="¿Cómo sería la boda de tus sueños?";
    Preguntas[70]="¿Qué te gustaría cambiar de tu cuerpo?";
    Preguntas[71]="¿Quién es tu persona favorita y por qué?";
    Preguntas[72]="¿Alguna vez has contado una mentira durante un juego de verdad o reto? ¿Qué fue y por qué?";
    Preguntas[73]="¿Cuál es tu mayor miedo?";
    Preguntas[74]="¿Qué pasó en el peor día de tu vida?";
    Preguntas[75]="¿Cuál sería tu poder si pudieras ser un superhérore?";
    Preguntas[76]="¿Qué película elegirías si pudieras convertirla en tu vida?";
    Preguntas[77]="¿Cuál es tu talento especial?";
    Preguntas[78]="¿Cuál es la mejor comida que has probado?";
    Preguntas[79]="¿Cuál es tu película favorita de Disney y por qué?";
    Preguntas[80]="¿Qué harías con un millón de dólares si alguna vez ganaras la lotería?";
    Preguntas[81]="Danos una lista de 10 artículos o cosas que compraste y nunca utilizaste o lamentaste comprar";
    Preguntas[82]="¿Cuál ha sido tu mayor humillación?";
    Preguntas[83]="¿Cuál es tu cualidad personal o característica que te gustaría cambiar?";
    Preguntas[84]="¿Qué es lo más loco que te ha pasado en un centro comercial?";
    Preguntas[85]="¿Qué es lo peor que has hecho en tu vida?";
    Preguntas[86]="¿Alguna vez pensaste en engañar a tu novio / novia?";
    Preguntas[87]="¿Alguna vez has mentido a tu pareja para evitar un momento íntimo, por ejemplo, decir que te duele la cabeza?";
    Preguntas[88]="¿Cuál es la broma más cruel que le has gastado a alguien?";
    Preguntas[89]="¿Cuál es la cosa más embarazosa que has puesto en las redes sociales?";
    Preguntas[90]="¿Cuál es la peor mentira que le has dicho a tus padres?";
    Preguntas[91]="¿En qué pelea que has tenido has ganado? ¿Y perdido?";
    Preguntas[92]="¿Cuál es la cosa que más te molesta que hace tu mamá?";
    Preguntas[93]="¿Cuál es la cosa que más te molesta de tu papa?";
    Preguntas[94]="¿Cuál es la historia más divertida que tus abuelos te han contado?";
    Preguntas[95]="¿Cuál era tu canción favorita en tu infancia?";
    Preguntas[96]="¿Cómo es la casa de tus sueños?";
    Preguntas[97]="¿Cuál es el periodo más largo que has pasado sin bañarte y por qué?";
    Preguntas[98]="¿Has llevado la misma ropa por más de 3 días?";
    Preguntas[99]="¿Qué animal serías?";
    Preguntas[100]="¿Qué dinosaurio serías?";
    Preguntas[101]="¿Qué supervillano serías?";
    Preguntas[102]="¿Con qué celebridad estás obsesionado?";
    Preguntas[103]="¿Cuál es el video YouTube más divertido que has visto?";
    Preguntas[104]="¿Quién es el peor maestro que has tenido y por qué?";
    Preguntas[105]="¿Cuál es tu equipo deportivo favorito?";
    Preguntas[106]="¿Cuál es tu canción favorita en este momento?";
    Preguntas[107]="¿Podrías pasar dos meses sin hablar con tus amigos?";
    Preguntas[108]="¿Podrías pasar dos meses sin tu teléfono?";
    Preguntas[109]="¿Podrías pasar dos meses sin ver televisión?";
    Preguntas[110]="¿Podrías pasar dos meses sin conectarte a las redes sociales?";
    Preguntas[111]="¿Qué prejuicio albergas secretamente?";
    Preguntas[112]="¿Cuántos años tenías cuando diste tu primer beso?";
    Preguntas[113]="¿Qué harías si tu novio o novia acabara con su relación en este momento?";
    Preguntas[114]="¿Si pudieras salir con algún famoso con quién sería?";
    Preguntas[115]="¿Qué es lo más gracioso que te ha sucedido durante una cita romántica?";
    Preguntas[116]="¿Qué harías si te encontraras mucho dinero en la calle?";
    Preguntas[117]="¿Cuál fue tu primera impresión de tu novia o novio cuando se conocieron?";
    Preguntas[118]="¿Si tuvieras que casarte con alguien que no te gusta, con quién te casarías?";
    Preguntas[119]="Si te encontraras en una isla desierta y tuvieras que elegir a un amigo para que te hiciera compañía, ¿a quién elegirías?";
    Preguntas[120]="¿Alguna vez un amigo ha coqueteado con tu pareja?";
    Preguntas[121]="¿En qué condiciones le mentirías a un amigo?";
    Preguntas[122]="¿Cuál creerías que puede ser una pregunta bastante incómoda?";
    Preguntas[123]="¿Alguna vez has robado algo? ¿Qué robaste y por qué lo hiciste?";
    Preguntas[124]="¿Qué es lo más estúpido que has hecho en tu vida?";
    Preguntas[125]="¿Si no estuvieras aquí, que estarías haciendo en este momento?";
    Preguntas[126]="¿Qué es lo más vergonzoso que te ha sucedido estando desnudo?";
    Preguntas[127]="¿Si pudieras hacer lo que quisieras, cuál sería tu trabajo soñado?";
    Preguntas[128]="¿Qué quieres hacer durante los próximos años?";
    Preguntas[129]="Si pudieras ser otra persona, ¿quién serías?";
    Preguntas[130]="¿Qué te gustaría inventar?";
    Preguntas[131]="Si pudieras nacer de nuevo, ¿dónde te gustaría nacer? ¿Quién te gustaría ser?";
    Preguntas[132]="¿A qué le tienes miedo? ¿Por qué?";
    Preguntas[133]="¿Cuál recuerdas como el peor día de tu vida? ¿Por qué?";
    Preguntas[134]="¿Alguna vez has actuado como un loco en un lugar público?";
    Preguntas[135]="¿Alguna vez has pretendido ser quien no eres para obtener algún beneficio?";
    Preguntas[136]="¿Qué harías si pudieras viajar en el tiempo?";
    Preguntas[137]="¿Alguna vez has espiado a alguien?";
    Preguntas[138]="¿Qué es lo que más te molesta?";
    Preguntas[139]="¿Qué harías si ganaras la lotería?";
    Preguntas[140]="¿Qué es lo más malicioso que has hecho en tu vida?";
    Preguntas[141]="¿Alguna vez has iniciado un rumor sobre alguien? ¿De qué se trataba?";
    Preguntas[142]="¿Cuál ha sido la fiesta más salvaje a la que has ido?";
    Preguntas[143]="¿Cuál ha sido la broma más desagradable que has hecho en tu vida?";
    Preguntas[144]="¿Alguna vez resultaste atractivo para alguien del mismo sexo? ¿Qué pasó? ¿Cuál fue tu reacción?";
    Preguntas[145]="¿Cuál ha sido el piropo más extraño que te han dicho?";
    Preguntas[146]="¿Cuál ha sido el peor rumor que has compartido? (sabiendo que no era cierto)";
    Preguntas[147]="¿Cuál ha sido el evento más traumático de tu vida?";
    Preguntas[148]="¿Qué es lo más estúpido que le ha dicho a su pareja durante un momento íntimo?";
    Preguntas[149]="¿Alguna vez has ocultado algo de tu pareja?";
    Preguntas[150]="¿Cuál ha sido la peor fiesta a la que has ido?";
    Preguntas[151]="¿Cuál ha sido el momento más feliz de tu vida?";
    Preguntas[152]="¿Alguna vez has actuado como turista para conseguir algo?";
    Preguntas[153]="¿Alguna vez has conducido borracho?";
    Preguntas[154]="¿Qué es lo más estúpido que has hecho al volante?";
    Preguntas[155]="¿Qué es lo más estúpido que le has dicho a una persona que te gusta?";
    Preguntas[156]="¿Cuál es la apuesta más estúpida que has hecho?";
    Preguntas[157]="¿Alguna vez te has escapado de clase?";
    Preguntas[158]="¿Alguna vez le dijiste a alguien que lo amabas, sin de verdad sentirlo?";
    Preguntas[159]="¿Alguna vez te han sacado de un bar o una discoteca?";
    Preguntas[160]="¿Quién fue tu amor de infancia?";
    Preguntas[161]="¿Has besado a alguno de tus amigos más cercanos? ¿Quién?";
    Preguntas[162]="¿Qué es lo más idiota que has hecho por dinero?";
    Preguntas[163]="Si pudieras tener una conversación con algún personaje histórico, ¿con quién sería?";
    Preguntas[164]="¿Alguna vez has sostenido una conversación contigo mismo en voz alta?";
    Preguntas[165]="¿Te has colado en una fiesta privada?";
    Preguntas[166]="¿Alguna vez has mentido para acostarte con alguien?";
    Preguntas[167]="¿Has tenido una experiencia cercana a la muerte?";
    Preguntas[168]="¿Has quedado en embarazo o has embarazado a alguien?";
    Preguntas[169]="¿Has besado a alguien que tenga el doble de tu edad?";
    Preguntas[170]="¿Alguna vez has estado esposado? ¿Por cuál razón?";
    Preguntas[171]="¿Alguna vez has engañado o has sido engañado?";
    Preguntas[172]="¿Quién fue tu mejor amigo en la infancia?";
    Preguntas[173]="¿Qué piensan la mayoría de tus amigos de ti que sea verdad y qué es totalmente falso?";
    Preguntas[174]="Si pudieras ser una celebridad, ¿quién serías?";
    Preguntas[175]="¿Campo, playa o montaña?";
    Preguntas[176]="¿Has comido animales crudos?";
    Preguntas[177]="¿Has hecho bullying?";
    Preguntas[178]="¿Te han hecho bullying?";
    Preguntas[179]="¿Serías capaz de asesinar a alguien?";
    Preguntas[180]="¿Cuál consideras que es tu peor defecto?";
    Preguntas[181]="¿Cuál es el mejor viaje que has hecho?";
    Preguntas[182]="¿Cuál es el mayor riesgo que has tomado?";
    Preguntas[183]="Si pudieras ser un color, ¿qué color serías?";
    Preguntas[184]="Si pudieras ser un olor, ¿qué olor serías?";
    Preguntas[185]="¿Alguna vez te has hecho pasar por otra persona?";
    Preguntas[186]="¿Qué es lo más cursi que le has dicho a alguien?";
    Preguntas[187]="¿Cómo te ves de aquí a 10 años?";
    Preguntas[188]="¿Qué prefieres: libros o películas?";
    Preguntas[189]="¿Cuál fue el mayor trauma de tu niñez?";
    Preguntas[190]="Al bañarte, ¿qué parte de tu cuerpo enjabonas primero?";
    Preguntas[191]="¿Cuál es la mayor asquerosidad que has hecho?";
    Preguntas[192]="¿Qué es lo mejor que has hecho en tu vida?";
    Preguntas[193]="¿Cuál crees que es tu peor fracaso?";
    Preguntas[194]="¿Crees en Dios?";
    Preguntas[195]="¿Qué es lo más asqueroso que has bebido?";
    Preguntas[196]="Si pudieras hacer algo peligroso con la seguridad de que no te pasaría nada malo, ¿qué harías?";
    Preguntas[197]="¿Alguna vez has hecho bromas telefónicas?";
    Preguntas[198]="¿Crees en los extraterrestres?";
    Preguntas[199]="¿Cuál juego era tu preferido cuando eras pequeño?";
    Preguntas[200]="¿Cuál es el momento más incómodo que has tenido en tu vida?";
    Preguntas[201]="¿Has estado alguna vez muy cerca de la muerte?";
    Preguntas[202]="¿Has tenido algún accidente automovilístico?";
    Preguntas[203]="¿Cuál es el peor viaje que has hecho?";
    Preguntas[204]="Si pudieras ser un instrumento musical, ¿cuál serías?";
    Preguntas[205]="Si pudieras ser un sonido, ¿cuál serías?";
    Preguntas[206]="¿Cuál es tu palabra favorita?";
    Preguntas[207]="¿Cuál es la palabra que menos te gusta?";
    Preguntas[208]="¿Qué sonido te gusta más?";
    Preguntas[209]="¿Qué profesión nunca llevarías a cabo?";
    Preguntas[210]="¿Qué es lo más asqueroso que has comido?";
    Preguntas[211]="¿Alguna vez has deseado ser alguien más?";
    Preguntas[212]="¿Cuál crees que es tu mejor virtud?";
    Preguntas[213]="¿Crees en la vida más allá de la muerte?";
    Preguntas[214]="¿Cuál es tu color preferido?";
    Preguntas[215]="¿Cuál es tu comida preferida?";
    Preguntas[216]="¿En qué ocasión te has sentido inseguro de ti mismo?";
    Preguntas[217]="¿Qué te quita el sueño?";
    Preguntas[218]="¿Qué te relaja?";
    Preguntas[219]="¿Qué es lo más desconsiderado que has hecho?";
    Preguntas[220]="¿Qué es lo que más te gusta hacer?";
    Preguntas[221]="Si pudieras ser una flor, ¿qué flor serías?";
    Preguntas[222]="¿Alguna vez has convivido con alguna pareja?";
    Preguntas[223]="¿Alguna vez has estado en una relación sin querer estar?";
    Preguntas[224]="¿Qué es lo más considerado que has hecho?";
    Preguntas[225]="¿A qué persona odias?";
    Preguntas[226]="¿Sabes si alguna persona te odia?";
    Preguntas[227]="¿Cómo te describirías en tres palabras?";
    Preguntas[228]="¿Alguna vez te has comido tus propios mocos?";
    Preguntas[229]="¿Alguna vez te has sacado los mocos en público?";
    Preguntas[230]="¿Alguna vez ha perdido a una mascota?";
    Preguntas[231]="¿Ha fallecido algún amigo cercano?";
    Preguntas[232]="¿Qué prefieres: frío o calor?";
    Preguntas[233]="Si pudieras ser una bebida, ¿cuál serías?";
    Preguntas[234]="Si pudieras ser una comida, ¿cuál serías?";
    Preguntas[235]="¿Cuál es tu miedo más oscuro?";

    /*srand(time(NULL));

    int aleatoverdad= (rand()%numPreguntas)+1;*/
    int aleatoverdad=aleatorio(numPreguntas);

    int numRetos=36;
    string Retos[numRetos];
    Retos[0]="Gritar en la calle que te has enamorado";
    Retos[1]="Cantar y bailar como loco.Declararte a la persona que te gusta";
    Retos[2]="Llama a algún número desconocido y canta feliz cumpleaños";
    Retos[3]="Abrazar a la primera persona que te encuentres en la calle";
    Retos[4]="Subirse a cantar en la barra de un bar";
    Retos[5]="Tomate una foto embarazosa y publícala en tus redes sociales";
    Retos[6]="Actúa como un animal (el grupo elige)";
    Retos[7]="Quítate los calcetines con los dientes";
    Retos[8]="Da 10 vueltas y trata de caminar en línea recta";
    Retos[9]="Elige a tres personas del grupo y que elijan tres ingredientes de la cocina.Mézclalos y tómatelo";
    Retos[10]="No puedes decir malas palabras durante el resto del juego.Baila la macarena";
    Retos[11]="Ponte los zapatos al revés y mantenlos así.Toma una cucharada de picante";
    Retos[12]="Besa la parte de atrás del cuello de la persona que está a tu derecha";
    Retos[13]="Dale un serenata a la persona que está al frente de ti";
    Retos[14]="Vístete con tu camisa al revés";
    Retos[15]="Canta cualquier cosa que digas durante el resto del juego";
    Retos[16]="Baila de froma vergonzosa la cancion que el grupo elija";
    Retos[17]="Recrea una escena de una pelicula tonta con tu mejor amigo";
    Retos[18]="Publica en una red social: Amo a [nombre de la persona que más odias]";
    Retos[19]="Sube la foto mas vergonzosa de tu galeria a tu red social favorita";
    Retos[20]="Tómate una foto coqueta y mándasela a tu papá, como si fuera un error";
    Retos[21]="Enviarle un texto a tu novio y termina la relación con una falsa excusa";
    Retos[22]="Dale un me gusta a la foto mas antigua de Instagram de la persona que te gusta";
    Retos[23]="Mójate el cabello y canta y baila frente a todos Loca de Shakira";
    Retos[24]="Recibe una cachetada de cada lado de uno de los jugadores";
    Retos[25]="Tomate una foto haciendo muecas y ponla de estado";
    Retos[26]="Haz 20 abdominales seguidos!";
    Retos[27]="Haz 20 sentadillas seguidas!";
    Retos[28]="Haz 20 ranas seguidas!";
    Retos[29]="Haz 20 planchas seguidas!";
    Retos[30]="Ve a la calle y abraza a un poste";
    Retos[31]="Llama a tu ex y decirle que lo/a extrañas";
    Retos[32]="Tómate una foto en la que salgas muy fe@ y envíasela a la persona que te gusta";
    Retos[33]="Díle un priopo al primer extraño que pase por la calle";
    Retos[34]="Canta a todo pulmón la canción más tonta que hayas escuchado";
    Retos[35]="Camina como un pingüino alrededor de la habitación";

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
