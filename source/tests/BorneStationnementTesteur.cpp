/**
 * \file BorneStationnementTesteur
 * \brief implémentation des tests unitaire de la classe BorneStationnementTesteur.
 * \auteur djodji Komlan
 * \date 26/03/2021
 */

#include<gtest/gtest.h>
#include"Borne.h"
#include"ContratException.h"
#include "BorneStationnement.h"
#include<sstream>
#include<iostream>

using namespace std;
using namespace bornesQuebec;

/**
 * \brief Test du constructeur
 *        cas valides: Création d'un objet Borne et verifie de l'assignation des valeurs
 *          passées en parametre.
 *         cas invalide: lectureMetrique<0.0
 *                        segmentRue <0
 *                       numBorne superieur a 4 chiffre
 *                       coteRue ne correspont au point de cardinalité
 */

TEST (BorneSationnement, PamaretreValides)
{

  BorneStationnement borneStationnementTest (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, 23.7, 20, 2172, "Nord");

  ASSERT_FLOAT_EQ (23.7, borneStationnementTest.reqLectureMetrique ());
  ASSERT_EQ (20, borneStationnementTest.reqSegmentRue ());
  ASSERT_EQ (2172, borneStationnementTest.reqNumBorne ());
  ASSERT_EQ ("Nord", borneStationnementTest.reqCoteRue ());

}

/**
 * \ les cas invalides
 */

// Lescture Metrique Invalide

TEST (BorneStationnement, lectureMetriqueInvalide)
{
  ASSERT_THROW (BorneStationnement t_LectureMetrique (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, -34.32, 20, 2172, "Nord"), PreconditionException);

}

//Segment Rue Invalide

TEST (BorneStationnement, segmentRueInvalide)
{
  ASSERT_THROW (BorneStationnement t_SegmentRue (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, 23.7, -20, 2172, "Nord"), PreconditionException);
}

//Numero Borne Invalide

TEST (BorrneStationnement, numBorneInvalide)
{
  ASSERT_THROW (BorneStationnement t_NumBorne (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, 23.7, 20, 23456, "Nord"), ContratException);
}

//Cote Rue Invalide

TEST (BorneStationnement, coteRueInvalide)
{
  ASSERT_THROW (BorneStationnement t_CoteRue (300070, "Nord", "Boulevard Rene Levesque Est", -71.22669, 46.814323, 23.7, 20, 2172, ""), ContratException);
}

/**
 * \brief Creation d'une Fixture a utiliser pour les methode public de la classe BorneStationnement
 */

class UneBorneStationnement : public::testing::Test
{
public:

  UneBorneStationnement () : borneStationnement (300070, "Nord", "Boulevard René-Levesque Est", -71.22669, 46.814323, 34.32, 20, 2172, "Est") { }

  BorneStationnement borneStationnement;
};

/**
 * \ test Test de la methode reqLectureMetrique()
 *         cas valide: Verifie le retour de la valeur de lecture Metrique
 *          cas invalide: aucun
 */

TEST_F (UneBorneStationnement, reqLectureMetrique)
{
  ASSERT_FLOAT_EQ (34.32, borneStationnement.reqLectureMetrique ());

}

/**
 * \test Test de la methode reqSegmentRue()
 *        cas valide: verifie le retour de la valeur du segment Rue
 *         cas invalide: aucun
 */

TEST_F (UneBorneStationnement, reqSegmentRue)
{
  ASSERT_EQ (20, borneStationnement.reqSegmentRue ());
}

/**
 * \test Test de la methode reqNumeBorne()
 *        cas valide: verifie le retour de la valeur du coté Rue
 *         cas invalide: aucun
 */

TEST_F (UneBorneStationnement, reqNumBorne)
{
  ASSERT_EQ (2172, borneStationnement.reqNumBorne ());
}

/**
 * \test Test de la methode req()
 *        cas valide: verifie le retour de la valeur du coté Rue
 *         cas invalide: aucun
 */

TEST_F (UneBorneStationnement, reqCoteRue)
{
  ASSERT_EQ ("Est", borneStationnement.reqCoteRue ());
}

/**
 *
 * \brief Test de la methode reqBorneFontaine qui augmente la methode de la classe Borne
 *        cas valide: Vérifie le retour des informations sur l'objet Borne
 *        cas invalide: aucun
 */
TEST_F (UneBorneStationnement, reqBorneFormate)
{
  ostringstream os;
  os << "Borne de stationnement " << endl;
  os << "----------------------------------------------" << endl;
  os << borneStationnement.Borne::reqBorneFormate ();
  os << "Distance mesuree : " << borneStationnement.reqLectureMetrique () << endl;
  os << "Segment de rue : " << borneStationnement.reqSegmentRue () << endl;
  os << "Numero de la borne : " << borneStationnement.reqNumBorne () << endl;
  os << "Cote de la rue : " << borneStationnement.reqCoteRue () << endl;
  os << "----------------------------------------------------" << endl;
  ASSERT_EQ (os.str (), borneStationnement.reqBorneFormate ());

}