//tp1.c
#include "Basic.h"       // mode de base
//#include "Automated.h"
//#include "Console.h"
#include "tcv.h"         // declaration de mes fonctions
#include <stdio.h>       // printf
#include <stdbool.h>     // bool true false

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* NOS fonctions de tests *********************/

/**
 * Test d'assertions pour l'intervalle de 17.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc 17.0 = 170.
 *
 * Test pour validerTH_1(int n)
 *
 */
void test_validerTH_1(void) {


    CU_ASSERT_TRUE(validerTH_1(170));
    CU_ASSERT_TRUE(validerTH_1(390));
    CU_ASSERT_TRUE(validerTH_1(400));

    CU_ASSERT_FALSE(validerTH_1(169));
    CU_ASSERT_FALSE(validerTH_1(401));
    CU_ASSERT_FALSE(validerTH_1(-400));

}
/**
 * Test d'assertions pour l'intervalle de 17.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc 17.0 = 170.
 * Cast en char pour la compilation et l'execution.
 *
 * Test pour validerTH_2(char n)
 *
 */
void test_validerTH_2(void) {

    CU_ASSERT_TRUE(validerTH_2((char)170));
    CU_ASSERT_TRUE(validerTH_2((char)390));
    CU_ASSERT_TRUE(validerTH_2((char)400));

    CU_ASSERT_FALSE(validerTH_2((char)169));
    CU_ASSERT_FALSE(validerTH_2((char)401));
    CU_ASSERT_FALSE(validerTH_2((char)-400));

}
/**
 * Test d'assertions pour l'intervalle de 17.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc 17.0 = 170.
 *
 * Test pour validerTH_3(short n)
 *
 */
void test_validerTH_3(void) {

    CU_ASSERT_TRUE(validerTH_3(170));
    CU_ASSERT_TRUE(validerTH_3(390));
    CU_ASSERT_TRUE(validerTH_3(400));

    CU_ASSERT_FALSE(validerTH_3(169));
    CU_ASSERT_FALSE(validerTH_3(401));
    CU_ASSERT_FALSE(validerTH_3(-400));

}
/**
 * Test d'assertions pour la temperature ambiante de -40.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc -40.0 = -400.
 *
 * Test pour validerTA_1(int n)
 */
void test_validerTA_1(void) {

    CU_ASSERT_FALSE(validerTA_1(-401));
    CU_ASSERT_FALSE(validerTA_1(401));
    CU_ASSERT_FALSE(validerTA_1(505));

    CU_ASSERT_TRUE(validerTA_1(0));
    CU_ASSERT_TRUE(validerTA_1(-400));
    CU_ASSERT_TRUE(validerTA_1(400));
}
/**
 * Test d'assertions pour la temperature ambiante de -40.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc -40.0 = -400.
 *
 * Cast en char pour compilation et fonctionnement.
 *
 * Test pour validerTA_2(char n)
 */
void test_validerTA_2(void) {

    CU_ASSERT_FALSE(validerTA_2((char)-401));
    CU_ASSERT_FALSE(validerTA_2((char)401));
    CU_ASSERT_FALSE(validerTA_2((char)505));

    CU_ASSERT_TRUE(validerTA_2((char)0));
    CU_ASSERT_TRUE(validerTA_2((char)-400));
    CU_ASSERT_TRUE(validerTA_2((char)400));
}

/**
 * Test d'assertions pour la temperature ambiante de -40.0 a 40.0 Celsius.
 * Afin de fonctionner, les decimales sont entieres donc -40.0 = -400.
 *
 * Test pour validerTA_3(short n)
 */
void test_validerTA_3(void) {

    CU_ASSERT_FALSE(validerTA_3(-401));
    CU_ASSERT_FALSE(validerTA_3(401));
    CU_ASSERT_FALSE(validerTA_3(505));

    CU_ASSERT_TRUE(validerTA_3(0));
    CU_ASSERT_TRUE(validerTA_3(-400));
    CU_ASSERT_TRUE(validerTA_3(400));
}
/**
 * Test d'assertions pour la pulsation de 50 a 200 bpm.
 *
 * Test pour validerPulsation_1(int n)
 */
void test_validerPulsation_1(void) {
    CU_ASSERT_FALSE(validerPulsation_1(49));
    CU_ASSERT_FALSE(validerPulsation_1(201));
    CU_ASSERT_FALSE(validerPulsation_1(-10));

    CU_ASSERT_TRUE(validerPulsation_1(50));
    CU_ASSERT_TRUE(validerPulsation_1(200));
    CU_ASSERT_TRUE(validerPulsation_1(125));
}
/**
 * Test d'assertions pour la pulsation de 50 a 200 bpm.
 *
 * Cast en char pour compilation et fonctionnement.
 *
 * Test pour validerPulsation_2(char n)
 */
void test_validerPulsation_2(void) {
    CU_ASSERT_FALSE(validerPulsation_2((char)49));
    CU_ASSERT_FALSE(validerPulsation_2((char)201));
    CU_ASSERT_FALSE(validerPulsation_2((char)-10));

    CU_ASSERT_TRUE(validerPulsation_2((char)50));
    CU_ASSERT_TRUE(validerPulsation_2((char)200));
    CU_ASSERT_TRUE(validerPulsation_2((char)125));
}
/**
 * Test d'assertions pour la pulsation de 50 a 200 bpm.
 *
 *
 * Test pour validerPulsation_3(short n)
 */
void test_validerPulsation_3(void) {
    CU_ASSERT_FALSE(validerPulsation_3(49));
    CU_ASSERT_FALSE(validerPulsation_3(201));
    CU_ASSERT_FALSE(validerPulsation_3(-10));

    CU_ASSERT_TRUE(validerPulsation_3(50));
    CU_ASSERT_TRUE(validerPulsation_3(200));
    CU_ASSERT_TRUE(validerPulsation_3(125));
}
/**
 * Test d'assertions pour l'intensite du signal de -85 a -25.
 *
 *
 * Test pour validerSignal_1(int n)
 */
void test_validerSignal_1(void) {
    CU_ASSERT_FALSE(validerSignal_1(-86));
    CU_ASSERT_FALSE(validerSignal_1(-24));
    CU_ASSERT_FALSE(validerSignal_1(0));

    CU_ASSERT_TRUE(validerSignal_1(-85));
    CU_ASSERT_TRUE(validerSignal_1(-25));
    CU_ASSERT_TRUE(validerSignal_1(-55));
}

/**
 * Test d'assertions pour l'intensite du signal de -85 a -25.
 *
 * Cast en char pour compilation et fonctionnement.
 *
 * Test pour validerSignal_2(char n)
 */
void test_validerSignal_2(void) {
    CU_ASSERT_FALSE(validerSignal_2((char)-86));
    CU_ASSERT_FALSE(validerSignal_2((char)-24));
    CU_ASSERT_FALSE(validerSignal_2((char)0));

    CU_ASSERT_TRUE(validerSignal_2((char)-85));
    CU_ASSERT_TRUE(validerSignal_2((char)-25));
    CU_ASSERT_TRUE(validerSignal_2((char)-55));
}
/**
 * Test d'assertions pour l'intensite du signal de -85 a -25.
 *
 *
 * Test pour validerSignal_3(short n)
 */
void test_validerSignal_3(void) {
    CU_ASSERT_FALSE(validerSignal_3(-86));
    CU_ASSERT_FALSE(validerSignal_3(-24));
    CU_ASSERT_FALSE(validerSignal_3(0));

    CU_ASSERT_TRUE(validerSignal_3(-85));
    CU_ASSERT_TRUE(validerSignal_3(-25));
    CU_ASSERT_TRUE(validerSignal_3(-55));
}
/************* Nous debutons l'execution des tests **************/

int main ( void )
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if ( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite( "tp1_test_Suite", init_suite, clean_suite );
    if ( NULL == pSuite ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ( (NULL == CU_add_test(pSuite, "test_validerTH_1", test_validerTH_1)) ||
         (NULL == CU_add_test(pSuite, "test_validerTH_2", test_validerTH_2)) ||
         (NULL == CU_add_test(pSuite, "test_validerTH_3", test_validerTH_3)) ||
         (NULL == CU_add_test(pSuite, "test_validerTA_1", test_validerTA_1)) ||
         (NULL == CU_add_test(pSuite, "test_validerTA_2", test_validerTA_2)) ||
         (NULL == CU_add_test(pSuite, "test_validerTA_3", test_validerTA_3)) ||
         (NULL == CU_add_test(pSuite, "test_validerPulsation_1", test_validerPulsation_1)) ||
         (NULL == CU_add_test(pSuite, "test_validerPulsation_2", test_validerPulsation_2)) ||
         (NULL == CU_add_test(pSuite, "test_validerPulsation_3", test_validerPulsation_3)) ||
         (NULL == CU_add_test(pSuite, "test_validerSignal_1", test_validerSignal_1)) ||
         (NULL == CU_add_test(pSuite, "test_validerSignal_2", test_validerSignal_2)) ||
         (NULL == CU_add_test(pSuite, "test_validerSignal_3", test_validerSignal_3)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
/*
   // LES modes interactifs
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
