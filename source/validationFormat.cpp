/**
 * \file:    Validation Format.cpp
 * \brief:   L'implémentation des différentes fonctions de validation
 * \author:  Djodji Komlan
 * \date:    18 février 2021, 20:07
 */

#include <iostream>
#include <sstream>
#include <string>
#include "validationFormat.h"
#include <cstdlib>


/**
 * \brief      extraire informations relatives à des bornes de paiement
 * \param[out] p_ligne, information extraite
 * \param[in]  p_parametre, permettant le stockage des inofrmations extraites.
 * \return un booléen.
 *
 */
using namespace std;

namespace util
{

  bool
  valideLigneCVS (const std::string & p_ligne, std::ostringstream & p_parametres)

  {
    bool val = false;
    int compteurBarre = 0;
    for (int i = 0; i < p_ligne.length (); i++)
      {
        if (p_ligne[i] == '|')
          {
            compteurBarre++;
          }

      }

    if (compteurBarre == 8)
      {

        std::istringstream is_chaine (p_ligne);

        string id;
        getline (is_chaine, id, '|');



        string cote_rue;
        getline (is_chaine, cote_rue, '|');

        string lect_met;
        getline (is_chaine, lect_met, '|');


        string segment_ru;
        getline (is_chaine, segment_ru, '|');

        string direction;
        getline (is_chaine, direction, '|');


        string nom_topog;
        getline (is_chaine, nom_topog, '|');


        string no_borne;
        getline (is_chaine, no_borne, '|');


        string longitude;
        getline (is_chaine, longitude, '|');


        string latitude;
        getline (is_chaine, latitude, '|');


        if (!id.empty () &&!cote_rue.empty () &&!lect_met.empty ()&& !segment_ru.empty ()&& !nom_topog.empty () && !no_borne.empty ()&& !longitude.empty ()&& !latitude.empty ())
          {
            p_parametres << id << "," << cote_rue << "," << lect_met << "," << segment_ru << "," << direction << "," << nom_topog << "," << no_borne << "," << longitude << "," << latitude;

            val = true;
          }

      }
    return val;
  }

  /**
   * \brief valider la longitude et la latitude borne de stationnement.
   * \param[in] chaine de caractère à convertir.
   * \return un booléen.
   */
  bool
  validerGeom (const std::string & p_geom)
  {

    string new_p_geom = "";

    for (int i = 0; i < p_geom.size (); i++)
      {
        new_p_geom += p_geom[i];
      }

    string part1 = new_p_geom.substr (0, 7);
    string last1 = new_p_geom.substr (new_p_geom.size () - 1);
    string middle = new_p_geom.substr (7);
    middle.pop_back ();

    if (part1 != "POINT (" || last1 != ")")
      {
        return false;
      }

    bool next = false;

    string num1asString = "";
    string num2asString = "";

    for (int i = 0; i < middle.length (); i++)
      {
        if (next == false)
          {
            if (isspace (middle[i]))
              {
                next = true;
              }
            else
              {
                num1asString += middle[i];
              }
          }
        else
          {

            num2asString += middle[i];
          }
      }

    if (num1asString.empty () || num2asString.empty ())
      {
        return false;
      }

    double firstDouble = convertirChaineEnDouble (num1asString);
    double secondDouble = convertirChaineEnDouble (num2asString);

    return true;
    ;

  }

  /**
   * \briel extraire informations bornes de stationnements
   * \param[in] p_enregistrement chaine de caractere extrait
   * \param[in] p_attribut stockage informations extraites.
   * \return un booléen.
   */

  bool
  valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs)
  {

    return false;
  }

  /**
   * \brief Méthode qui permet de convertir une chaîne de caractères
   *         de la forme 123,456 en double.
   * \param[in] p_chaine la chaîne de caractères à convertir.
   * \return un double résultat de la conversion.
   */
  double
  convertirChaineEnDouble (const std::string& p_chaine)
  {
    string chaineFormate = p_chaine;
    //on remplace la , en .
    for (unsigned int i = 0; i < chaineFormate.length (); i++)
      {
        if (chaineFormate[i] == ',')
          {
            chaineFormate[i] = '.';
          }
      }
    istringstream is (chaineFormate);
    double chaineConvertiEnDouble;
    is >> chaineConvertiEnDouble;
    return chaineConvertiEnDouble;
  }

  /**
   * \brief  fonction validant le format d'un point cardinal.
   * \param  p_cardinalité regroupe les valeurs possible d'un point cardinal
   * \return un string correspondant à la cardinalité (Nord, Sud, Est, Ouest, null , chaine vide)
   */

  bool
  validerPointCardinal (const std::string &p_cardinalite)
  {
    bool valide = false;

    if (p_cardinalite.empty () || p_cardinalite == "Nord" || p_cardinalite == "Sud" || p_cardinalite == "Est" || p_cardinalite == "Ouest" || p_cardinalite == "Null")
      {
        valide = true;
      }
    return valide;
  }

  bool
  arrondissementEstValide (const std::string&p_ville, const std::string &p_arrondissement)
  {
    if (p_ville == "Quebec")
      {
        return !p_arrondissement.empty ();
      }
    return true;
  }

}// namspace util
