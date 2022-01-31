
/**
 * \file BorneFontaineTesteur
 * \brief implémentation des tests unitaire de la classe BorneFontaine.
 * \auteur djodji Komlan
 * \date 26/03/2021
 */

#include<gtest/gtest.h>
#include"Borne.h"
#include"ContratException.h"
#include "BorneFontaine.h"
#include<sstream>
#include<iostream>


using namespace std;
using namespace bornesQuebec;

/**
 * \test Test du constructeur
 *      cas valides: ville non vide et arrondissement vide si la ville est Québec
 *      cas non valide: ville est vide
 */
TEST (BorneFontaine, parametreValide)
{
  BorneFontaine borneFontaineTest (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, "Levis", "OutreMont");
  ASSERT_EQ ("Levis", borneFontaineTest.reqVille ());
  ASSERT_EQ ("OutreMont", borneFontaineTest.reqArrondissement ());

}

/**
 * \cas invalide
 */
// faire un fiture pour tester ce

TEST (BorneFontaine, parametreVilleInvalide)
{

  ASSERT_THROW (BorneFontaine borneFontaineTest (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, "", "OutreMont"), ContratException);
}

/**
 * \brief Test de la methode reqBorneFontaine qui augmente la methode de la classe Borne
 *        cas valide: Vérifie le retour des informations sur l'objet Borne
 *        cas invalide: aucun
 */

/**
 * \brief Creation d'une Fixture a utiliser pour les methode public de la classe BorneFontaine
 */

class UneBorneFontaine : public::testing::Test
{
public:

  UneBorneFontaine () : f_borneFontaine (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, "Levis", "OutreMont") { }

  BorneFontaine f_borneFontaine;
};

/**
 * \ test Test de la methode reqVille
 *         cas valide: Verifie le retour de la valeur de la ville
 *          cas invalide: aucun
 */
TEST_F (UneBorneFontaine, ReqVille)
{
  ASSERT_EQ ("Levis", f_borneFontaine.reqVille ());

}

/**
 * \ test Test de la methode reqArrondissement
 *         cas valide: Verifie le retour de la valeur de l'arrondissement
 *          cas invalide: aucun
 */
TEST_F (UneBorneFontaine, reqArrondissement)
{
  ASSERT_EQ ("OutreMont", f_borneFontaine.reqArrondissement ());
}

/**
 *
 * \brief Test de la methode reqBorneFormate qui augmente la methode de la classe Borne
 *        cas valide: Vérifie le retour des informations sur l'objet Borne
 *        cas invalide: aucun
 */
TEST_F (UneBorneFontaine, reqBorneFormate)
{
  ostringstream os;
  os << "Borne-fontaine " << endl;
  os << "----------------------------------------------" << endl;
  os << f_borneFontaine.Borne::reqBorneFormate ();
  os << "Ville: " << f_borneFontaine.reqVille () << endl;
  os << "Arrondissement: " << f_borneFontaine.reqArrondissement () << endl;
  os << "----------------------------------------------------" << endl;
  ASSERT_EQ (os.str (), f_borneFontaine.reqBorneFormate ());
}
