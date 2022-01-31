/**
 * \file RegistreBorneTesteur
 * \brief implémentation des tests unitaire de la classe RegistreBorneTesteur.
 * \auteur djodji Komlan
 * \date 26/03/2021
 */

#include <gtest/gtest.h>
#include"Borne.h"
#include"ContratException.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include<sstream>
#include<iostream>

using namespace std;
using namespace bornesQuebec;

/**
 * \brief Test du constructeur
 *        cas valides: La version du registre n'est pas vide
 *         cas invalide: la version du registre est vide
 */

TEST (RegistreBorne, PamaretreValides)
{
  RegistreBorne registreBorneTest ("Ville Québec");
  ASSERT_EQ ("Ville Québec", registreBorneTest.reqNomRegistreBorne ());

}

/**
 * \cas invalide de parametre du constructeur
 */

TEST (RegistreBorne, nomInvalide)

{
  ASSERT_THROW (RegistreBorne NomInvalide (""), PreconditionException);
}

/**
 * \brief Creation d'une Fixture a utiliser pour les methode public de la classe RegistreBorne
 */
class RegistreBorneFixture : public::testing::Test
{
public:

  RegistreBorneFixture () : RegistreBorne_f ("Montreal") { }

  RegistreBorne RegistreBorne_f;
};

/**
 * \ test Test de la methode reqNomRegistreBorne()
 *         cas valide: Verifie le retour de la valeur de lecture du nom du registre
 *          cas invalide: aucun
 */

TEST_F (RegistreBorneFixture, reqNomRegistreBorne)
{
  ASSERT_EQ ("Montreal", RegistreBorne_f.reqNomRegistreBorne ());
}

/**
 * \ test Test de la methode reqRegistreBorneFormate()
 *         cas valide: Verifie le retour de la valeur du registre Borne Formaté
 *          cas invalide: aucun
 */

TEST_F (RegistreBorneFixture, reqRegistreBorneFormate)
{
  BorneFontaine laBorneFontaine (1234, "Nord", "Sainte-foy", -54325, 6553, "Montreal", "Cap-Rouge");
  RegistreBorne_f.ajouteBorne (laBorneFontaine);


  std::ostringstream os;
  os << "Registre: " << RegistreBorne_f.reqNomRegistreBorne () << std::endl;
  os << laBorneFontaine.reqBorneFormate ();


  ASSERT_EQ (os.str (), RegistreBorne_f.reqRegistreBorneFormate ());

}

/**
 * \test Test de la methode de l'opérateur d'assignation ()
 *
 */

TEST_F (RegistreBorneFixture, assignationRegistre)
{

  BorneFontaine laBorneFontaine (1234, "Nord", "Sainte-foy", -54325, 6553, "Montreal", "Cap-Rouge");
  RegistreBorne_f.ajouteBorne (laBorneFontaine);

  RegistreBorne assigneRegistreBorne ("Riviere");

  RegistreBorne assigneRegistreBorneTwo ("Montreal");

  assigneRegistreBorne = assigneRegistreBorneTwo;

  ASSERT_EQ (RegistreBorne_f.reqNomRegistreBorne (), assigneRegistreBorne.reqNomRegistreBorne ());

  //std::cout << RegistreBorne_f.reqRegistreBorneFormate ();
}

/**
 * \test Test du constructeur Copie()
 *
 */

TEST_F (RegistreBorneFixture, constructeurParCopie)
{
  BorneFontaine laBorneFontaine (1234, "Nord", "Sainte-foy", -54325, 6553, "Montreal", "Cap-Rouge");
  RegistreBorne_f.ajouteBorne (laBorneFontaine);

  RegistreBorne autreRegistreBorne ("RégitreTest");
  autreRegistreBorne = RegistreBorne_f;

  ASSERT_EQ (RegistreBorne_f.reqNomRegistreBorne (), autreRegistreBorne.reqNomRegistreBorne ());
}

