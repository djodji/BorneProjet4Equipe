/**
 * \file    Principal.cpp
 * \brief   Programme permettant l'utilisation de la classe Borne.
 * \author  Djodji Komlan
 * \date    21 février 2021, 14:14
 */

#include <cstdlib>
#include <cctype>
#include "Borne.h"
#include "validationFormat.h"
#include<iostream>
#include"BorneFontaine.h"
#include"RegistreBorne.h"
#include"BorneStationnement.h"

using namespace std;
using namespace bornesQuebec;

///**
// * \fn int main()
// * \brief fonction main pour utiliser la classe Borne
// */

int
main ()
{

  int identifiant;
  int identifiant2;
  string direction;
  string nomTopographique;
  float longitude;
  float latitude;
  string ville;
  string arrondissement;
  float lectureMetrique;
  int segmentRue;
  int numBorne;
  string coteRue;




  do
    {
      cout << "Veuillez entrer l'identifiant de la borne :";
      cin >>identifiant;
    }
  while (identifiant < 0);


  do
    {
      cout << "Veuillez entrer le seconde identifiant de la borne :";
      cin >>identifiant2;
    }
  while (identifiant2 < 0);


  do
    {

      cout << "Veuillez entrer la direction, première lettre majiscule : ";
      cin>>direction;

    }
  while (!util::validerPointCardinal (direction));

  do
    {
      cin.ignore ();
      cout << "Veuillez entrer le nom topographique : ";
      char buffer[256];
      cin.getline (buffer, 256);
      nomTopographique = buffer;
    }
  while (nomTopographique.empty ());


  do
    {
      cout << "Veuillez entrer la longitude: ";
      cin >> longitude;
    }
  while (longitude == 0);

  do
    {
      cout << "Veuillez entrer la latitude: ";
      cin >> latitude;
    }
  while (latitude == 0);

  do
    {
      cin.ignore ();
      cout << "Veuillez entrer le nom de la ville: ";
      char buffer[256];
      cin.getline (buffer, 256);
      ville = buffer;
    }
  while (ville.empty ());

  do
    {
      cin.ignore ();
      cout << "Veuillez entrer le nom de l'arrondissement : ";
      char buffer[256];
      cin.getline (buffer, 256);
      arrondissement = buffer;
    }
  while (!util::arrondissementEstValide (ville, arrondissement));

  do
    {
      cout << "Veuillez entrer la distance mesurée :";
      cin >>lectureMetrique;
    }
  while (lectureMetrique < 0.0);

  do
    {
      cout << "Veuillez entrer le segment de Rue:";
      cin >>segmentRue;
    }
  while (segmentRue < 0);


  do
    {
      cout << "Veuillez entrer le numero de la Borne:";
      cin >>numBorne;
    }
  while (numBorne < 0 || numBorne > 9999);


  do
    {
      cout << "Veuillez entrer Cote de la rue, première lettre en majiscule: ";
      cin>> coteRue;

    }
  while (!util::validerPointCardinal (coteRue));
  cout << endl;
  cout << endl;


  BorneFontaine laBorneFontaine (identifiant2, direction, nomTopographique, longitude, latitude, ville, arrondissement);


  BorneStationnement laBorneStationnement (identifiant, direction, nomTopographique, longitude, latitude, lectureMetrique, segmentRue, numBorne, coteRue);



  RegistreBorne laRegistreBorne ("borne de la ville de Québec 2021");

  laRegistreBorne.ajouteBorne (laBorneStationnement);


  laRegistreBorne.ajouteBorne (laBorneFontaine);
  cout << laRegistreBorne.reqRegistreBorneFormate ();


  return 0;
}



