# Vernam

Programme permettant d'encoder, de décoder et de créer une clé avec le système de Vernam.

## Compilation

Utilisez la commande suivante pour compiler le programme :

```bash
make
```

## Utilisation

### Création d'une clé

La clé de Vernam doit posséder la même longueur que celle du message, lors de l'execution de la commande le programme prend donc en argument le **message à encoder en fichier d'entrée** pour obtenir sa longueur. Le programme prend également en argument le nom du **fichier de sortie qui contiendra la clé générée**.

```bash
./vernam -k [fichier d'entrée] [fichier de sortie]
```

Exemple :

```bash
./vernam -k message.txt cle.txt
```

### Encodage

Pour encoder un message, utilisez la commande suivante où le **fichier d'entrée correspond au message à encoder**, le **fichier clé au fichier contenant la [clé de Vernam généré préalablement](#création-d-une-clé)** et le **fichier de sortie qui contiendra le message codé** :

```bash
./vernam -c [fichier d'entrée] [fichier clé] [fichier de sorite]
```

Exemple :

```bash
./vernam -c message.txt cle.txt message_codé.txt
```

### Décodage

Pour décoder un message, utilisez la commande suivante où le **fichier d'entrée correspond au message à décoder**, le **fichier clé au fichier contenant la clé de Vernam utilisé pour l'encodage du message** et le **fichier de sortie qui contiendra le message décodé** :

```bash
./vernam -d [fichier d'entrée] [fichier clé] [fichier de sorite]
```

Exemple :

```bash
./vernam -d message_codé.txt cle.txt message_décodé.txt
```

## Limites

### Caractères utilisés

Certains caractères tels que les caractères accentuées ne peuvent pas être décodés correctement.