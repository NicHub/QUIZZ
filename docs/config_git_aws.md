
**CONFIGURATION AWS GIT**
=========================

<http://docs.aws.amazon.com/codecommit/latest/userguide/welcome.html>

# PIP + AWS CLI

	aws --version

si < 1.7.36 ⇒ il faut mettre à jour <http://docs.aws.amazon.com/cli/latest/userguide/installing.html#install-with-pip>

# Creation du profil “nicoAWSCodeCommit”

	aws configure --profile nicoAWSCodeCommit

AKIAJ7UUPPDXW5T7IMPA
DWXTZkBhTgK32FcMKNbKmuSbN0l5CC/EU4UyhdIH
us-east-1

# Modification de la config git

	nano ~/.gitconfig

[credential]
	helper = !aws --profile nicoAWSCodeCommit codecommit credential-helper $@
	UseHttpPath = true

# Clone du repository

git clone https://git-codecommit.us-east-1.amazonaws.com/v1/repos/QUIZZ quizz-aws



# Autentification par SSH

Malheureusement, l’authentification par HTTPS ne fonctionne pas sur le rPi. Il faut utiliser SSH

<http://docs.aws.amazon.com/codecommit/latest/userguide/setting-up-ssh-unixes.html>

nicoAWSCodeCommit_rsa

Host git-codecommit.*.amazonaws.com
  User APKAIQMXVIBOHG3MZIKA
  IdentityFile ~/.ssh/nicoAWSCodeCommit_rsa


git clone ssh://git-codecommit.us-east-1.amazonaws.com/v1/repos/QUIZZ quizz-aws



# Keychain

Le mot de passe est modifié automatiquement toutes les 15 min par AWS. Il faut donc supprimer celui enregistré dans le Keychain “git-codecommit.us-east-1.amazonaws.com”

Le mot de passe peut être supprimé avec la commande :

	security delete-internet-password -l "git-codecommit.us-east-1.amazonaws.com" ~/Library/Keychains/login.keychain
