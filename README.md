# Dilatation et érosion binaire sur une image de format BITMAP
Projet consistant à pouvoir faire un ensemble d'érosion binaire

---

## Sommaire
* [Installation][Installation]
    * [Compilation][Compilation]
    * [Utilisation][Utilisation]
* [Résultat de l'application][Result]
* [Complément][Complement]

---

## Installation
pour utiliser le projet il faut dans un premier temps se placer dans le projet, ce que vous pouvez faire avec les lignes suivantes
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
del *.o
```

___Pour Linux :___
```shell
gcc *.c -c
gcc *.o -o program
rm -rf *.o
```

### Utiliation
Dans le cas où aucun paramètre n'est rentré à la suite de l'appel du programme. Il utilisera une image Lenna comme exemple. l'execution du programme se fait selon la ligne suivante :
```shell
program [chemin/du/fichier.bmp]
```
---

## Résultat de l'application
Voilà un exemple avec la séquence suivante `eeeddd` 3 fois avec un type de connexion 8:
![img1](https://image.noelshack.com/fichiers/2018/25/1/1529349088-sans-titre-1.jpg)
---

## Complément
Le programme vous demandera d'écrire une sequence de `e` (pour une erosion) et de `d` (pour une dilatation). 
Dans un second temps il faudra chosir un type de connexion entre 4 et 8.

_à poursuivre_


[gcc]: https://gcc.gnu.org
[Installation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#installation
[Compilation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#compilation
[Utilisation]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#utiliation
[Result]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#r%C3%A9sultat-de-lapplication
[Complement]: https://github.com/A1c0/Dilatation_erosion_binaire_bitmap#compl%C3%A9ment
