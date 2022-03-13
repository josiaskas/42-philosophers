# Philosophers
Qui aurait cru que philosopher serait si mortel ?

## Jeu

-	Des philosophes (un philosophe minimum) sont assis autour d’une table ronde
-	Les philosophes sont soit en train de manger, de penser ou de dormir Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir. Lorsqu’ils dorment, ils ne peuvent pas manger ou penser. Enfin, lorsqu’ils pensent, ils ne peuvent pas manger ou dormir.
-	Il y a autant de fourchettes que de philosophes.
-	un philosophe prend la fourchette sur sa gauche et celle sur sa droite, soit une fourchette dans chaque main, afin de manger.
-	Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un
philosophe meurt de faim.
-	Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
-	Les philosophes ne communiquent pas entre eux.
-	Les philosophes ne peuvent pas savoir si l’un d’entre eux est sur le point de mourir.
-	Inutile de préciser que les philosophes ne doivent pas mourir !
-	Une fourchette est placée entre chaque paire de philosophes
-	Chaque philosophe doit être représenté par un thread.
-	Afin d’empêcher les philosophes de dupliquer les fourchettes, vous devez protéger leur état en mémoire avec un mutex pour chacune d’entre elle.
-	philosophe numéro N est assis entre philosophe numéro N - 1 et philosophe numéro N + 1.

## Choix fait

-	les fourchettes sont des mutex empechant les philosophe de manger en desordre.
-	Faire partir les philos pairs ou impairs avec du retard.
-	Utiliser le thread prinicpal pour checker.
