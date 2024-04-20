# p31

En premier lieu, faites un **fork** de ce dépôt de sorte à en avoir une copie à vous sur ce serveur GitLab dans laquelle vous pourrez ajouter vos réalisations.
Une fois ce **fork** réalisé, changez son niveau de visibilité en "Privé" puis partagez-le avec votre enseignant de TP en l'ajoutant en tant que `Reporter`.

Une fois cela fait, vous pouvez **cloner** votre dépôt :
```
git clone git@git.unistra.fr:[votre login]/p31.git
```

Vous vous retrouvez alors devant un dossier `p31` qui contient une copie locale de votre dépôt.

De nouvelles ressources seront ajoutés au fur et à mesure sur le dépôt de référence depuis lequel vous avez forké votre dépôt.
De manière à pouvoir les récupérer, vous pouvez ajouter une nouvelle **remote** à la configuration de votre dépôt local :
```
git remote add upstream git@git.unistra.fr:p_31/p31.git
```

`upstream` est le nom que l'on a choisi ici de donner à cette nouvelle remote (on aurait pu choisir un autre nom).
C'est en général comme cela que l'on appelle le dépôt de référence depuis lequel on a forké son dépôt.
Vous pouvez constater qu'il a bien été ajouté en exécutant cette commande (qui liste les remotes connues) :
```
git remote -v
```

Pour récupérer les commits ajoutés sur le dépôt de référence, vous pouvez dorénavant faire :
```
git pull upstream main
```

`main` est ici le nom de la branche par défaut dans laquelle vous travaillez.
Nul besoin de faire plus de gestion de branches dans le cadre de ce module.
