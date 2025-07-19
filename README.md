
[![made at 42](https://img.shields.io/badge/made%20at-42-blue?logo=42)](https://42.fr)
[![norminette passed](https://img.shields.io/badge/norminette-passed-brightgreen)](https://github.com/Lejusdefruits/Rush01)
[![stars](https://img.shields.io/github/stars/Lejusdefruits/Rush01?style=social)](https://github.com/Lejusdefruits/Rush01/stargazers)
[![forks](https://img.shields.io/github/forks/Lejusdefruits/Rush01?style=social)](https://github.com/Lejusdefruits/Rush01/network/members)

---

## Table des matières

- [présentation](#présentation)
- [fichiers attendus](#fichiers-attendus)
- [progress](#project-progress)
- [compilation](#compilation)
- [utilisation](#utilisation)
- [exemple de sortie](#exemple-de-sortie)
- [features cool du repo](#features-cool-du-repo)
- [contributors](#contributors)

---

## Présentation

ce projet est le deuxième rush de la piscine c à 42  
le but : coder un solveur pour le puzzle skyscrapers (4x4) en c, avec gestion des contraintes de visibilité  
objectif principal : respecter la norme, travailler en team, structurer le code et push avant la deadline

---

## Fichiers attendus

- `main.c` : parse les arguments et lance la résolution
- `solve.c` : backtracking et algo principal
- `views.c` : vérifie les contraintes de visibilité sur chaque ligne/colonne
- `utils.c` : parsing, affichage, gestion d’erreurs, trucs utiles
- `makefile` : pour compiler simplement le projet

---

## Project progress

- [x] main.c
- [x] solve.c
- [x] views.c
- [x] utils.c
- [x] makefile

---

| [Marc Chevalier](https://profile-v3.intra.42.fr/users/marcheva) | [Guillaume Fouquier](https://profile-v3.intra.42.fr/users/guifouqu) | [Julien Brousse](https://profile-v3.intra.42.fr/users/jubrouss) |
| :-------------------------------------------------------------: | :-------------------------------------------------------------: | :-----------------------------------------------------------------: |

---

## compilation

pour compiler le projet  
```sh
cc -wall -wextra -werror main.c solve.c views.c utils.c -o rush01
