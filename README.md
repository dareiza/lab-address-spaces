# The Abstraction: Address Spaces #

En esta tarea aprenderemos sobre unas herramientas útiles para examinar el uso de memoria virtual de sistemas basados en Linux. 
Esto solo será una breve pista de lo que es posible; será necesario sumergirse más profundamente para convertirte verdaderamente 
en un experto (¡Como siempre!).

## Antes de empezar ##

Para responder a las preguntas lea y reflexione sobre el capítulo [The Abstraction: Address Spaces]( http://pages.cs.wisc.edu/~remzi/OSTEP/vm-intro.pdf) pues de este fue del que se sacaron las preguntas. Adicionalmente entienda y ejecute el código asociado a dicho capítulo el cual se encuentra en el siguiente [enlace](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/vm-intro). 

Adicionalmente, donde crea que sea necesario haga uso de los conceptos sobre procesos aprendidos en el laboratorio anterior.

## Preguntas ##

1. La primera herramienta que analizaremos es una herramienta muy simple, ```free```. Primero, abra una terminal de Linux y
teclee ```man free```, lea su manual entero; es breve, no se preocupe! ¿Para qué sirve este comando?. **Nota**: Puede apoyarse en
material web para entender la herramienta mediante ejemplos.
R/ El comando ```free``` muestra la cantidad total de memoria libre y usada en el sistema tanto física como de intercambio (swap), así como los buffers y cache usados por el kernel.

2. Ahora, ejecute ```free``` usando algunos argumentos que podrían ser útiles (por ejemplo, ```-m```, para mostrar
la cantidad total de memoria en megabytes).

https://raw.githubusercontent.com/dareiza/lab-address-spaces/master/imagenes/free.png

¿Cuánta memoria hay en su sistema?
R/-hay 5851 megas de memoria.
¿Cuánta está libre?
R/hay un total de 2197 megas libres para memoria y 2047 megas libres para el swap
¿Son estos valores los que usted esperaba?
R/Sí debido a la memoria de mi computador los resultados que arroja free fueron acertados a lo que se esperaba

3. A continuación, cree un pequeño programa que use cierta cantidad de memoria, llamado ```memory-user.c```.
Este programa debe tomar un argumento por línea de comandos: el número de megabytes de memoria que usted usará.
Cuando lo ejecute, el programa debe separar memoria para un arreglo (vector) y recorrer el arreglo,
accediendo consecutivamente a cada entrada (por ejemplo, escribiendo un valor inicial a cada posición). El programa deberá hacer esto indefinidamente o,
por lo menos, por una cierta cantidad de tiempo especificada también por línea de comandos.

4. Ahora, mientras corra su programa ```memory-user.c```, ejecute la herramienta ```free``` (en una terminal diferente, pero en la misma máquina).
¿Cómo cambia el uso total de memoria cuando su programa está corriendo?
R/ Como se esperaba mientras el programa `memory-user.c` está corriendo al ejecutar free varias veces se pudo notar como se pudo notar como la memoria usada iba en aumento, esto se puede evidenciar en la siguiente imagen.
/home/dan/Labs/lab-address-spaces/imagenes/freePunto4.png
¿Qué pasa cuando se finaliza el programa memory-user (comando kill)?, ¿coinciden los valores con lo que usted esperaba? En efecto ocurrió lo esperado ya que la memoria libre vuelve a aumentar cuando se usa el comando kill.
/home/dan/Labs/lab-address-spaces/imagenes/kill.png
Intente esto para diferentes cantidades de uso de memoria. ¿Qué pasa cuando usted usa cantidades de memoria realmente grandes?

5. Ahora veremos una herramienta más conocida como ```pmap```. Invierta algo de tiempo para leer el manual de ```pmap```
en detalle. ¿Cuál es la diferencia de ```pmap``` con ```free```? La diferencia es que  free me retorna la cantidad total de memoria indicando la cantidad que está en uso y la cantidad libre, por otro lado el comando pmap indica el mapa de memoria de un proceso o procesos.

6. Para usar pmap, usted tiene que conocer el identificador de proceso (PID) del proceso en el que usted está interesado.
Por lo tanto, primero ejecute ```ps auxw``` para ver una lista con todos lo procesos; entonces, seleccione alguno de su interés tal como un browser. Usted también puede usar su programa memory-user en este caso (de hecho, usted puede hacer que ese programa llame a ```getpid()``` para imprimir su PID para su conveniencia).
R/ este punto va en conjunto con el 7

7. Ahora ejecute ```pmap``` en alguno de estos procesos usando varias flags (como ```-X```) para revelar más detalles acerca del proceso.
¿Qué puede ver?
R/ Al usar el flag -d nos trae el tamaño en Kbytes, el Offset y el device, al usar -q podemos ver que a diferencia de usar el pmap sin ningún flag este no nos muestra el total de memoria, por último al usar -XX este nos arrojó toda información que nos provee el kernel la cual se puede ver en la siguiente imagen
/home/dan/Labs/lab-address-spaces/imagenes/pmap-XX.png
¿Cuántas entidades diferentes conforman un espacio de direcciones moderno, a diferencia de nuestra simple concepción de code/stack/heap?

8. Finalmente, ejecute ```pmap``` para su programa memory-user, con diferentes cantidades de memoria usada.
¿Qué puede ver en este caso?
R/En este caso al ejecutar pmap con diferentes cantidades de memoria empezando por una cantidad baja y aumentandola notando que cada vez la cantidad de memoria usada es mayor.
¿La salida de ```pmap``` es siempre la que usted espera?
R/ En efecto es el resultado que se esperaba ya que a mayor cantidad de memoria asignada el total de memoria que usa el proceso debe ser mayor.

## Referencias ##

1. http://u.cs.biu.ac.il/~linraz/os/OS3.pdf
2. https://www.ostechnix.com/run-command-specific-time-linux/
3. http://u.cs.biu.ac.il/~linraz/os/OS4.pdf
4. http://u.cs.biu.ac.il/~linraz/os/OS5.pdf
