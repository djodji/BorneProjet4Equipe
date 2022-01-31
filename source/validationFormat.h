/**
 * \file    validation Format.h
 * \brief   Les différents prototypes de la fonction validation format
 * \author  Djodji Komlan
 * \date    18 février 2021, 20:07
 */

#ifndef VALIDATIONFORMAT__H
#define VALIDATIONFORMAT__H
#include <string>

/**
 * \namespace util
 * \brief   l'espace de nom util regroupant les déclarations de fonctions
 *          spécifiques au développement de validation Format.
 */
namespace util
{


  bool valideLigneCVS (const std::string & p_ligne, std::ostringstream & p_parametres);
  bool validerGeom (const std::string & p_geom);
  bool valideStationemementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs);
  double
  convertirChaineEnDouble (const std::string& p_chaine);
  bool validerPointCardinal (const std::string &p_cardinalite);
  bool arrondissementEstValide (const std::string& p_ville, const std::string& p_arrondissement);

}
// fin namspace util
#endif /* VALIDATIONFORMAT__H */

