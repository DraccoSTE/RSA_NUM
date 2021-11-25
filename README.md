# LAB 7: RSA

El algoritmo implementado crea una clase llamada rsa, donde posteriormente declaramos las variables necesarias, las privadas (p,q,phi y d) las cuales son los dos primos, phi que sera la multiplicacion de cada uno disminuido por una unidad y la clave d, la inversa de la clave e, pasando a las publicas (n y e) que no necesitan seguridad y son de conocimiento publico.
Realizado esto tendremos que crear dos métodos creadores de la clase, uno que recibe parametros, que es para el emisor y uno que no los recibe, que es para el receptor.
El creador del emisor inicializa p y q usando una funcion de la Libreria NTL para conseguir primos menores a N, luego asigna n a la multiplicacion ed los primos y phi a la multiplicacion de ambos menos uno, luego usaremos otra funcion de NTL para generar un numero random, el cual luego evaluamos y volveremos a generar si es menor a 2 o si su mcd con phi no es 1 (osea si no es coprimo con phi), luego haremos el extendido de euclides de e y phi para conseguir la inversa de e, la cual asignaremos a d, que si es negativa la haremos pasar por el modulo phi para conseguir una positiva.
Dentro de esta clase tambien declaramos nuestros métodos necesarios para el correcto funcionamiento de este como las funciones get, que permiten usar variables privadas, la funcion modulo, euclides y euclides extendido, muy usadas dentro del algoritmo y en su metodo creador.
//faltaaaaaaaaaaa

