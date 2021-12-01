# Integral_B
Se tiene una texto con un registro de diferentes ciudades, dichas ciudades se organizan en un grafo, donde establecemos conexiones entre ellas. Usamos una estrcutura de hashing para guardar valores de distancia usando como Keys los nombres de dichas ciudades. 
El usuario puede ver cual es la ruta optima desde punto A a punto B y asi mismo su distancia 
El usuario puede agregar nuevas ciudades y su conexion con las existentes 

# SICT0302B: Toma decisiones

#Graph:

Teniendo una base de datos con ciudades se genera un grafo capaz de almacenar la relacion entre ellas previamente establecidas por el programa y a si mismo el Usuario puede ingresar nuevas ciudades junto con sus relaciones con otras.

Usando un DFS buscamos que dependiendo de las ciudades ingresados por el usuario se le presente la mejor ruta para llegar al destino deseado.

#Hashing:

Usamos un estructura de Hashing para almacenar la distancia entre ciudades, y es capaz de generar nuevas distancias conforme el usuario agregue nuevas ciudades.

Tomando como referencia las ciudades usadas por el DSF usamos la funcion get para obtener la distancia en ese especifico caso.

# SEG0702A Tecnologías de Vanguardia

Como nuevo algoritmo no visto en clase se implemento un algortimo de ordenamiento llamado Radix
Dicho algortimo esta en el archivo.h llamado "radix.h" y se manda a llamar en el main para buscar cual es la ciudad mas cercana a la ciudad de origen.

El Radix sort funciona de la siguiente manera, recibe un serie de datos, en este caso un array con diversos integers, y analiza los numeros digito por digito empezando por el menos significativo al mas significativo y usa una subrutina llamada countSort

El Radix sort cuenta con una complejidad O(nk) donde n es el numero de valores en el array y k es la longitud de los mismos

Dicho algortimo cuenta con las siguientes funciones dentro de el:

 #getMax:
 
 Recibe el array y el tamaño del mismo
 
 Funcion utilizada para obtener el numero mas grande del array y con ello obtener el maximo numero de digitos que se encuentran presentes
 
 #countSort:
 
 Es la subrutina del algoritmo, esta funcion recibe el array, su tamaño, y una variable que determina que digito se esta comparando con los demas. Es decir esa variable empieza comparando unidades,luego decenas, centenas y asi sucesivamente hasta concordar con el numero maximo de digitos. 
 
 Esta funcion recorre el array, toma cada valor y almacena los digitos en un nuevo array, los reorganiza en funcion del digito que se busque, ya sea unidades o decenas, y copia ese nuevo array organizando en el array original 
 
 #radixSort:
 
 Funcion que se llama en el main, en esta funcion se llama a llamar la funcion getMax(), y dentro de un ciclo for se llama countSort() en este ciclo se genera la variable que determina que digitos se iran comparando, unidades, decenas, centenas, y es la que usa countSort() para reorganizar el array. 
 
 #print: 
 
 Funcion utilizada para mostrar los valores al usuario, en nuestro caso solo nos importa el primer numero del nuevo array ordenado

EJEMPLO:

Queremos que un array se organize del menor valor al mayor:

Tenemos un array de la siguiente manera: 
        [170, 45, 75, 90, 2, 802, 2, 66]
        
Se empieza por las unidades y organizan en grupos si son iguales:        
        [{170, 90}, {2, 802, 2}, {45, 75}, {66}]
        
Luego continuan las decenas y nuevamente se organizan por grupos:
        [{02, 802, 02}, {45}, {66}, {170, 75}, {90}]
        
Por ultimo comparamos las centenas:
        [{002, 002, 045, 066, 075, 090}, {170}, {802}]
        
Este seria el array que se nos regresaria:
        [002, 002, 045, 066, 075, 090, 170, 802]

Referencias:

https://www.geeksforgeeks.org/radix-sort/

https://www.cs.usfca.edu/~galles/visualization/RadixSort.html


# SICT0303B: Implementa acciones científicas
#Mecanismos de consulta:
* El programa cuenta con un menu donde al usuario se le pregunta que busca hacer:
 
 1.-Viaje: se le presentan al usuario las ciudades registradas obtenidas de leer el txt y el selecciona desde donde iniciar y a donde busca llegar, en funcion de eso se implemente el DFS para obtener la mejor ruta posible, y posteriormente usando la ciudad que ingreso el usuario se usa como key para que nuestro hash nos diga la distancia a la que esta una de otra.
 
 2.- Agregar Ciudades: el usuario tiene la opcion de agregar nuevas ciudades, una a la vez, se escriben el txt, y el sistema muestra al usuario las demas ciudades y le pregunta a que ciudades esta conectadas, esto se hace para unir la nueva ciudad en el grafo.
 
 3.-Ciudad mas cercana: Al usuario se le presentan las ciudades y escoge alguna, tomando su eleccion como key para el hashing obtenemos las distancias entre todas las demas ciudades y usando el RadixSort imprime al usuario aquella con el numero mas pequeño  
 
 4.-Salir: el programa termina 
 
#Archivos:
* Archivo de texto "ciudades.txt" en donde estan almacenadas las ciudades utilizadas por el programa, el programa lee el archivo y alamcena las variables para la generacion de grafos y la generacion de las keys del hashing.

* Cada que el usuario registra una nueva ciudad, dicha ciudad se registra en el archivo .txt, se vuelve a ejecutar una lectura del mismo para actualizar tnato el grafo como las keys del hashing y una vez finalizado el programa, este borra las ciudades que se agregaron por el usuario y regresa asu estado original

* Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa., funciones o procedimientos que permitan al usaurio del programa consultar la información guardada en las estrcuturas de datos, es decir, hacer búsquedas u obtener valores específicos (no solo imprimir toda la estructura).
