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
/*
void test_case_exemple(void)
{
   // Les types d'assertions disponibles
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_TRUE(true);
   CU_ASSERT_FALSE(false);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/
void validerTH_1_Test(void) {

    CU_ASSERT_FALSE(validerTH_1(16));
    CU_ASSERT_FALSE(validerTH_1(41));
    CU_ASSERT_FALSE(validerTH_1(100));
    CU_ASSERT_FALSE(validerTH_1(0));
    CU_ASSERT_FALSE(validerTH_1(-40));


    CU_ASSERT_TRUE(validerTH_1(17));
    CU_ASSERT_TRUE(validerTH_1(18));
    CU_ASSERT_TRUE(validerTH_1(33));
    CU_ASSERT_TRUE(validerTH_1(39));
    CU_ASSERT_TRUE(validerTH_1(40));

}

void validerTH_2_Test(void) {

    CU_ASSERT_FALSE(validerTH_2(16));
    CU_ASSERT_FALSE(validerTH_2(41));
    CU_ASSERT_FALSE(validerTH_2(100));
    CU_ASSERT_FALSE(validerTH_2(0));
    CU_ASSERT_FALSE(validerTH_2(-40));

    CU_ASSERT_TRUE(validerTH_2(17));
    CU_ASSERT_TRUE(validerTH_2(18));
    CU_ASSERT_TRUE(validerTH_2(33));
    CU_ASSERT_TRUE(validerTH_2(39));
    CU_ASSERT_TRUE(validerTH_2(40));

}
void validerTH_3_Test(void) {

    CU_ASSERT_FALSE(validerTH_3(16));
    CU_ASSERT_FALSE(validerTH_3(41));
    CU_ASSERT_FALSE(validerTH_3(100));
    CU_ASSERT_FALSE(validerTH_3(0));
    CU_ASSERT_FALSE(validerTH_3(-40));

    CU_ASSERT_TRUE(validerTH_3(17));
    CU_ASSERT_TRUE(validerTH_3(18));
    CU_ASSERT_TRUE(validerTH_3(33));
    CU_ASSERT_TRUE(validerTH_3(39));
    CU_ASSERT_TRUE(validerTH_3(40));

}
void validerTA_1_Test(void) {

    //TODO

}

void max_test_trois(void) {

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
    if ( (NULL == CU_add_test(pSuite, "validerTH_1_Test", validerTH_1_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTH_2_Test", validerTH_2_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTH_3_Test", validerTH_3_Test)) ||
            (NULL == CU_add_test(pSuite, "validerTA_1_Test", validerTA_1_Test))
            )
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