
/**
 * \file BorneTesteurNouveau
 * \brief implémentation des tests unitaire de la classe Borne. cette classe est virtuelle
 *        on crée une autre classe concrete dérivée.
 * \auteur djodji Komlan
 * \date 26/03/2021
 */

#include<gtest/gtest.h>
#include"Borne.h"
#include"ContratException.h"
#include<iostream>

using namespace std;
using namespace bornesQuebec;

/**
 * \class BoreneDeTest
 * \brief classe de test permettant de tester la classe abstraite Borne
 */

class BorneDeTest : public Borne
{
public:

  BorneDeTest (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique, float p_longitude, float p_latitude) : Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude) { }

  /**
   * \brief methode permetant d'instanciée un objet Borne
   */
  virtual std::string
  reqBorneFormate () const
  {
    return Borne::reqBorneFormate ();
  }

  virtual Borne*
  clone () const
  {
    return (Borne*) this;
  }

  //virtual~Borne () { }
};


/**
 *\class uneBorne
 * \brief fixture uneBorne pour la creation d'un objet polygone pour les tests
 */

/**
 * \brief Test du constructeur Borne
 *          cas valide:
 *          constructeurAvecParametre: représente tous les types de Bornes
 *          présent dans la ville de Québec et verifie l'assignation de tous les attributs
 *          cas invalides:
 *          identifiant negatif
 *          direction un string ne correspondant pas au point cardinal
 *          nomTopographique vide
 */
TEST (BorneDeTest, ConstructeurBorneValide)
{
  BorneDeTest borneTest (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323);
  ASSERT_EQ (300070, borneTest.reqIdentifiant ());
  ASSERT_EQ ("Nord", borneTest.reqDirection ());
  ASSERT_EQ ("Boulevard Rene Levesque Est", borneTest.reqNomTopographique ());
  ASSERT_FLOAT_EQ (-71.22669, borneTest.reqLongitude ());
  ASSERT_FLOAT_EQ (46.814323, borneTest.reqLatitude ());
}

/**
 * \cas invalide
 */

TEST (BorneDeTest, constructeurInvalideIdentifiant)
{
  ASSERT_THROW (BorneDeTest borneTest (-12345, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323), ContratException);
}

TEST (BorneDeTest, constructeurInvalideDirection)
{
  ASSERT_THROW (BorneDeTest borneTest (300070, "", "Boulevard Rene Levesque Est", -71.22669, 46.814323), ContratException);
}

TEST (BorneDeTest, constructeurInvalideNomTopographique)
{
  ASSERT_THROW (BorneDeTest borneTest (300070, "Nord", "", -71.22669, 46.814323), PreconditionException);
}

TEST (BorneDeTest, constructeurInvalideLongitude)
{
  ASSERT_THROW (BorneDeTest borneTest (300070, "Nord ", "Boulevard Rene Levesque Est", 0.0, 46.814323), ContratException);
}

TEST (BorneDeTest, ConstructeurInvalideLongitude)
{
  ASSERT_THROW (BorneDeTest borneTest (300070, "Nord ", "Boulevard Rene Levesque Est", -71.22669, 0.0), ContratException);
}

/**
 * class uneBorne
 * Fixture uneBorne pour la creation d'un objet polygone pour les Test
 */

class UneBorne : public::testing::Test
{
public:

  UneBorne () : t_Borne (300070, "Sud", "1234 Rue Universite", -98.22669, 12.814323) { }

  BorneDeTest t_Borne;
};

/**
 * \test Test des methodes d'acces
 *          cas valide: verifie le retour de l'attribut passé en parametre
 *          cas invalide: aucun identifié
 */


TEST_F (UneBorne, reqIdentifiant)
{

  ASSERT_EQ (300070, t_Borne.reqIdentifiant ());
}

TEST_F (UneBorne, reqDirection)
{
  ASSERT_EQ ("Sud", t_Borne.reqDirection ());
}

TEST_F (UneBorne, ReqNomTopographique)
{
  ASSERT_EQ ("1234 Rue Universite", t_Borne.reqNomTopographique ());
}

TEST_F (UneBorne, reqLongitude)
{
  ASSERT_FLOAT_EQ (-98.22669, t_Borne.reqLongitude ());
}

TEST_F (UneBorne, ReqLatitude)
{
  ASSERT_FLOAT_EQ (12.814323, t_Borne.reqLatitude ());
}

/**
 * \test Test de la methode void asgNomTopographique(p_newNomTopographique)
 *      cas valide: non vide
 *      cas invalide: vide
 *
 */
TEST_F (UneBorne, p_newNomTopographiqueValide)
{
  t_Borne.asgNomTopographie ("1234 Rue Universite");
  ASSERT_EQ ("1234 Rue Universite", t_Borne.reqNomTopographique ());

}

TEST_F (UneBorne, p_newNomTopographiqueInvalide)
{
  ASSERT_THROW (t_Borne.asgNomTopographie (""), ContratException);
}

/**
 * \brief Test de la methode d'affichage reqBorneFormate()
 *         cas valide: verifie la chaine retounée
 *          cas invalide: aucun
 *
 */

TEST_F (UneBorne, reqBorneFormate)
{

  ostringstream os;
  os << "Identifiant de la borne: " << t_Borne.reqIdentifiant () << endl;
  os << "Direction: " << t_Borne.reqDirection () << endl;
  os << "Nom Topographique: " << t_Borne.reqNomTopographique () << endl;
  os << "Longitude: " << t_Borne.reqLongitude () << endl;
  os << "Latitude: " << t_Borne.reqLatitude () << endl;
  ASSERT_EQ (os.str (), t_Borne.reqBorneFormate ()) << endl;

  /**ASSERT_EQ (os.str (), t_Borne.reqBorneFontaine ());*/

}
