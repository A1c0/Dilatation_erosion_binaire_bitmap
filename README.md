# Dilatation et érosion binaire sur une image de format BITMAP
Projet consistant à pouvoir faire un ensemble de dilatation ou d'érosion binaire sur une image de format bitmap

---

## Sommaire
* [Installation][Installation]
    * [Compilation][Compilation]
    * [Utilisation][Utilisation]
* [Résultat de l'application][Result]
* [Complément][Complement]
    * [Dilatation et érosion binaire][Dil&Ero]
    * [Connexion 4 ou 8][Co48]

---

## Installation
pour utiliser le projet il faut dans un premier temps se placer dans le projet, ce que vous pouvez faire avec les 
lignes suivantes
```shell
git clone https://github.com/A1c0/Dilatation_erosion_binaire_bitmap.git
cd Dilatation_erosion_binaire_bitmap
```

### Compilation
Dans un second temps il vous faut compiler le projet à l'aide de l'outil _[gcc][gcc]_.

___Pour Windows :___
```shell
gcc *.c -c
gcc *.o -o program.exe
# pour supprimer les fichiers .o
del *.o
```

___Pour Linux :___
```shell
gcc *.c -c
gcc *.o -o program
# pour supprimer les fichiers .o
rm -rf *.o 
```

### Utilliation
Dans le cas où aucun paramètre n'est rentré à la suite de l'appel du programme. Il utilisera une image Lenna(en noir 
et blanc ou en couleur) comme exemple. l'execution du programme se fait selon la ligne suivante :

___Pour Windows :___
```shell
program [chemin/du/fichier.bmp]
```
___Pour Linux :___
```shell
./program [chemin/du/fichier.bmp]
```
---

## Résultat de l'application
Voilà un exemple avec la séquence suivante `eeeddd` 3 fois avec un type de connexion 8.
![imgRes](https://image.noelshack.com/fichiers/2018/25/1/1529349088-sans-titre-1.jpg)

---

## Complément
Le programme vous demandera d'écrire une sequence de `e` (pour une erosion) et de `d` (pour une dilatation) et dans 
un second temps il faudra chosir un type de connexion entre 4 et 8.
Nous allons developper dans cette partie ces notions.

### Dilatation et érosion binaire
Une dilatation ou une érosion binaire sont des opérations qui modifient une image pixel par pixel.

Une dilatation consiste à étendre un pixel sombre à ses pixels voisins plus clairs. Une érosion consiste en la même 
opération mais à l'inverse. Ainsi cette dernière consiste à étendre un pixel clair à ses pixels voisins plus sombres.
![imgDilEroBin](https://image.noelshack.com/fichiers/2018/25/2/1529412017-dilatationerosionbinaire.jpg)

### Connexion 4 ou 8
Une dilatation ou une érosion, comme précedemnt présenté, comme une opération qui se fait en fonctions des voisins du 
pixel traité. Une connexion 4 ou 8 consiste à préciser le nombre de voisins pris en compte comme sur la figure ci dessous.
![imgCo48](https://image.noelshack.com/fichiers/2018/25/2/1529415165-co48.jpg)

[gcc]: https://gcc.gnu.org
[Installation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#installation
[Compilation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#compilation
[Utilisation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#utiliation
[Result]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#r%C3%A9sultat-de-lapplication
[Complement]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#compl%C3%A9ment
[Dil&Ero]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#dilatation-et-erosion-binaire
[Co48]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#connexion-4-ou-8
