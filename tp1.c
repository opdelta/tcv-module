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


    CU_ASSERT_TRUE(validerTH_1(170));
    CU_ASSERT_TRUE(validerTH_1(390));
    CU_ASSERT_TRUE(validerTH_1(400));

    CU_ASSERT_FALSE(validerTH_1(169));
    CU_ASSERT_FALSE(validerTH_1(401));
    CU_ASSERT_FALSE(validerTH_1(-400));

}
void validerTH_2_Test(void) {

    CU_ASSERT_TRUE(validerTH_2((char)170));
    CU_ASSERT_TRUE(validerTH_2((char)390));
    CU_ASSERT_TRUE(validerTH_2((char)400));

    CU_ASSERT_FALSE(validerTH_2((char)169));
    CU_ASSERT_FALSE(validerTH_2((char)401));
    CU_ASSERT_FALSE(validerTH_2((char)-400));

}
void validerTH_3_Test(void) {

    CU_ASSERT_TRUE(validerTH_3(170));
    CU_ASSERT_TRUE(validerTH_3(390));
    CU_ASSERT_TRUE(validerTH_3(400));

    CU_ASSERT_FALSE(validerTH_3(169));
    CU_ASSERT_FALSE(validerTH_3(401));
    CU_ASSERT_FALSE(validerTH_3(-400));

}
void validerTA_1_Test(void) {

    CU_ASSERT_FALSE(validerTA_1(-401));
    CU_ASSERT_FALSE(validerTA_1(401));
    CU_ASSERT_FALSE(validerTA_1(505));

    CU_ASSERT_TRUE(validerTA_1(0));
    CU_ASSERT_TRUE(validerTA_1(-400));
    CU_ASSERT_TRUE(validerTA_1(400));
}
void validerTA_2_Test(void) {

    CU_ASSERT_FALSE(validerTA_2((char)-401));
    CU_ASSERT_FALSE(validerTA_2((char)401));
    CU_ASSERT_FALSE(validerTA_2((char)505));

    CU_ASSERT_TRUE(validerTA_2((char)0));
    CU_ASSERT_TRUE(validerTA_2((char)-400));
    CU_ASSERT_TRUE(validerTA_2((char)400));
}
void validerTA_3_Test(void) {

    CU_ASSERT_FALSE(validerTA_3(-401));
    CU_ASSERT_FALSE(validerTA_3(401));
    CU_ASSERT_FALSE(validerTA_3(505));

    CU_ASSERT_TRUE(validerTA_3(0));
    CU_ASSERT_TRUE(validerTA_3(-400));
    CU_ASSERT_TRUE(validerTA_3(400));
}
void validerPulsation_1_Test(void) {
    CU_ASSERT_FALSE(validerPulsation_1(49));
    CU_ASSERT_FALSE(validerPulsation_1(201));
    CU_ASSERT_FALSE(validerPulsation_1(-10));

    CU_ASSERT_TRUE(validerPulsation_1(50));
    CU_ASSERT_TRUE(validerPulsation_1(200));
    CU_ASSERT_TRUE(validerPulsation_1(125));
}

void validerPulsation_2_Test(void) {
    CU_ASSERT_FALSE(validerPulsation_2(49));
    CU_ASSERT_FALSE(validerPulsation_2(201));
    CU_ASSERT_FALSE(validerPulsation_2(-10));

    CU_ASSERT_TRUE(validerPulsation_2(50));
    CU_ASSERT_TRUE(validerPulsation_2(200));
    CU_ASSERT_TRUE(validerPulsation_2(125));
}
void validerPulsation_3_Test(void) {
    CU_ASSERT_FALSE(validerPulsation_3(49));
    CU_ASSERT_FALSE(validerPulsation_3(201));
    CU_ASSERT_FALSE(validerPulsation_3(-10));

    CU_ASSERT_TRUE(validerPulsation_3(50));
    CU_ASSERT_TRUE(validerPulsation_3(200));
    CU_ASSERT_TRUE(validerPulsation_3(125));
}
void validerSignal_1_Test(void) {
    CU_ASSERT_FALSE(validerSignal_1(-86));
    CU_ASSERT_FALSE(validerSignal_1(-24));
    CU_ASSERT_FALSE(validerSignal_1(0));

    CU_ASSERT_TRUE(validerSignal_1(-85));
    CU_ASSERT_TRUE(validerSignal_1(-25));
    CU_ASSERT_TRUE(validerSignal_1(-55));
}

void validerSignal_2_Test(void) {
    CU_ASSERT_FALSE(validerSignal_2(-86));
    CU_ASSERT_FALSE(validerSignal_2(-24));
    CU_ASSERT_FALSE(validerSignal_2(0));

    CU_ASSERT_TRUE(validerSignal_2(-85));
    CU_ASSERT_TRUE(validerSignal_2(-25));
    CU_ASSERT_TRUE(validerSignal_2(-55));
}
void validerSignal_3_Test(void) {
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
    if ( (NULL == CU_add_test(pSuite, "validerTH_1_Test", validerTH_1_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTH_2_Test", validerTH_2_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTH_3_Test", validerTH_3_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTA_1_Test", validerTA_1_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTA_2_Test", validerTA_2_Test)) ||
         (NULL == CU_add_test(pSuite, "validerTA_3_Test", validerTA_3_Test)) ||
         (NULL == CU_add_test(pSuite, "validerPulsation_1_Test", validerPulsation_1_Test)) ||
         (NULL == CU_add_test(pSuite, "validerPulsation_2_Test", validerPulsation_2_Test)) ||
         (NULL == CU_add_test(pSuite, "validerPulsation_3_Test", validerPulsation_3_Test)) ||
         (NULL == CU_add_test(pSuite, "validerSignal_1_Test", validerSignal_1_Test)) ||
         (NULL == CU_add_test(pSuite, "validerSignal_2_Test", validerSignal_2_Test)) ||
         (NULL == CU_add_test(pSuite, "validerSignal_3_Test", validerSignal_3_Test)))
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