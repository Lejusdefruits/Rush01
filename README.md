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

## contributors

- [marc chevalier](https://profile-v3.intra.42.fr/users/marcheva) |
- [julien brousse](https://profile-v3.intra.42.fr/users/jubrouss) |
- [guillaume fouquier](https://profile-v3.intra.42.fr/users/guifouqu)

---

## compilation

pour compiler le projet  
```sh
cc -wall -wextra -werror main.c solve.c views.c utils.c -o rush01
