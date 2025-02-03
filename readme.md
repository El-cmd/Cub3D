# Cub3D

## Description
Cub3D est un projet graphique inspiré du célèbre jeu Wolfenstein 3D, réalisé dans le cadre du cursus de l'école 42. Ce projet consiste à créer un moteur de ray-casting permettant de naviguer dans un labyrinthe en vue subjective.

## Prérequis
- Système d'exploitation Linux
- GCC
- Make
- Bibliothèques de développement X11

## Installation
```bash
git clone [votre-repo]
cd Cub3D
make
```

## 📦 Structure du Projet
```
Cub3D
├── src/
│   └── fichiers sources (.c)
├── includes/
│   └── fichiers d'en-tête (.h)
├── libft/
│   ├── sources de la libft
│   └── Makefile
├── minilibx-linux/
│   └── bibliothèque graphique
├── maps/
│   └── fichiers de configuration (.cub)
├── textures/
│   └── fichiers de textures
└── Makefile
```

## Utilisation
```bash
./cub3D [chemin_vers_la_carte.cub]
```

### Format du fichier de carte (.cub)
Le fichier de carte doit respecter le format suivant :
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Commandes
- `W A S D` : Déplacement
- `← →` : Rotation de la caméra
- `ESC` : Quitter le jeu

## Fonctionnalités
- Rendu 3D temps réel utilisant la technique du ray-casting
- Textures différentes pour chaque orientation des murs
- Collision avec les murs
- Mini-map (si implémentée)
- Gestion des couleurs du sol et du plafond

## License
Ce projet est réalisé dans le cadre du cursus de l'école 42.

## Note
Ce projet est un exercice pédagogique.