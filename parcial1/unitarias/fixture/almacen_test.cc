#include "gtest/gtest.h"
#include "warehouse.h"
#include <time.h>

// g++ -isystem ../../../googletest/include/ -std=c++11 -pthread almacen_test.cc ../gtest_main.a -o prueba

class TimeFixture : public testing::Test
{
public:
    virtual void  SetUp(){
        tiempo = time(NULL);    
    }
  
    virtual void TearDown()
    {
        EXPECT_TRUE((time(NULL) - tiempo) <= 10) << "tardo demasiado tiempo";
    }
private:
    time_t tiempo;
};

class WarehouseFixture : public TimeFixture
{
public:
    static Warehouse *w; 
    void SetUp(){
        TimeFixture::SetUp();
    }
    void TearDown()
    {
    	TimeFixture::TearDown();         
    }

    static void SetUpTestCase()
    {
        w = new Warehouse (10);
    }
    static void TearDownTestCase()
    {
        delete w;
        w = nullptr;
    }
};

Warehouse * WarehouseFixture::w = nullptr;

TEST_F(WarehouseFixture, Constructor) {
	ASSERT_EQ(10, w->capacity());
	delete w;
	w = new Warehouse(11);
	ASSERT_EQ(11, w->capacity());
}

TEST_F(WarehouseFixture, Add) {
	w->addBack(1);
	ASSERT_EQ(1, w->size());
	w->addFront(2);
	ASSERT_EQ(2, w->size());
}

TEST_F(WarehouseFixture, Deletion) {
	w->deleteElement(0);
	ASSERT_EQ(1, w->size());
}