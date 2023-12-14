# 1 

La fonction play de la classe Multimedia
Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

C'est une méthode abstraite il faut la déclarer avec =0 à la fin de la déclaration de la méthode.

# 2

Il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

Comme la classe de base contient une methode abstraite, elle devient elle même abstraite et il n'est plus possible de l'instancier.

# 3

Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau ou de les "jouer". Cette boucle doit traiter tous les objets dérivant de la classe de base de la même manière.

Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

La propriété caractéristique de l'orienté objet qui permet de faire cela est le polymorphisme.

# 4

Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

Il faut déclarer la méthode play comme virtuelle dans la classe de base.

# 5

Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

Le tableau doit contenir des pointeurs vers ces objets car les objets sont de taille variable et il faut donc les allouer dynamiquement. En Java, les objets sont alloués dynamiquement par défaut.

# 6

Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ? 

Il faut modifier la classe Film car elle contiennent un attribut qui est un pointeur vers des objet alloué dynamiquement. On créer donc une copie de l'objet dans le getter et le setter.

# 7

La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?

Le problème est que si on fait une copie de l'objet, les deux objets auront le même pointeur et donc si on modifie l'un, on modifie l'autre. Il faut donc faire une copie profonde de l'objet, faire une nouveau pointeur et copier les valeurs de l'objet dans le nouveau pointeur.

# 8

Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

Il faut que la liste d'objets soit une liste de pointeurs d'objets car les objets sont de taille variable et il faut donc les allouer dynamiquement. En Java, les objets sont alloués dynamiquement par défaut.


