# Libft
**Libft** est une bibliothèque personnalisée codée en C, comprenant des fonctions usuelles pour
faciliter les projets de 42. 
## Contenu
Cette bibliothèque inclut :
- **Fonctions de la libc** : Recodage des fonctions classiques comme `strlen`, `strchr`, `atoi`, etc.,
avec un préfixe `ft_`.
- **Fonctions supplémentaires** : Utilitaires comme `ft_split`, `ft_strjoin`, et autres pour manipuler
des chaînes et de la mémoire.
- **Partie bonus** : Gestion de listes chaînées avec des fonctions telles que `ft_lstnew`,
`ft_lstadd_front`, etc.
## Installation et Compilation
1. Clonez ce dépôt :
```bash
git clone https://github.com/JBmader/libft
cd libft
```
2. Compilez la bibliothèque avec le Makefile fourni :
```bash
make
```
Cela générera le fichier `libft.a` à la racine du projet.

3. Pour nettoyer les fichiers objets :
```bash
make clean
```
4. Pour nettoyer tout (y compris `libft.a`) :
```bash
make fclean
```
5. Pour tout recompiler depuis zéro :
```bash
make re
```


Projet réalisé par JBmader.
