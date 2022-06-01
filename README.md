# NOTECOM
### programme de prise de notes pour $bash & DOS.
-----
  ce programme permet de prendre des notes tout en étant dans un terminal Linux ou Windows.  
  la version ici présente est la première, de ce fait, les fonctionnalitées sont encore très simples.  
  
  le fichier .zip présent ici contient 3 versions exécutables du programme :
- une pour linux, identifié par l64.
- une pour windows en 32bits, identifié par w32.
- une pour windows en 64bits, identifié par w64.

  le programme source est en C, il est annoté, ce qui permet de bien voir le rôle des différentes fonctions qu'il contient.  
  
  pour le reste, voici les fonctionnalités du programme (ici, pour la version linux):  
- lire le fichier de note :

    $>  ./notecom_l64 -r  
  
  pour le moment, si le fichier de note n'existe pas, le système va retourner une erreur de type 'dump core'. ce cas de figure va être résolue dans la prochaine mise à jour.  
  
- écrire un message dans le fichier de note :

    $>  ./notecom_l64 -s "hello world !"
    $>
    
- écrire 'à la volée' dans le fichier de note :

    $>  ./notecom_l64 -e
    Ncom >>> vous pouvez écrire un message après l'autre dans ce mode...
    Ncom >>> pour finir il suffit d'écrire 'stop'
    Ncom >>> stop
    $>

- réinitialiser le fichier de note :

    $>  ./notecom_l64 -c
    ...le fichier notecom.txt a été vidé...
    $>
    
  à savoir que la réinitialisation du fichier de note écrase les données précédentes.
  
  par la suite, outre le problème de 'dump core', je compte également rajouter un fichier de configuration du programme, permettant de changer le fichier texte de destination.  
  
  Daniel, le 1 juin 2022.  
  
