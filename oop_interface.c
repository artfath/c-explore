#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* communication interface */
 typedef struct{
  struct com_func_table *func_table;
 }communication;

/* virtual table (a table of function pointers)*/
 typedef struct com_func_table{
  void(*receive)(communication * obj);
  void(*send)(communication * obj);
  void(*destroy)(communication * obj);
 }com_func_table;


/*UART class*/
/*attributes*/
typedef struct{
  communication super;
  char *payload;
}uart;

/* virtual table function uart*/
typedef struct{
  com_func_table super;
  void(*receive_new)(communication * obj, char *buffer);
}uart_func_table;

/*methods*/
void uart_receive(communication * obj){
  uart *uart_obj = (uart *)obj;
  printf("receive uart data : %s",uart_obj->payload );
}
void uart_receive_new(communication * obj, char * buffer){
  uart *uart_obj = (uart *)obj;
  uart_obj->payload = buffer;
}
void uart_send(communication * obj){
  uart *uart_obj = (uart *)obj;
  printf("send uart data : %s",uart_obj->payload );
}
void uart_destroy(communication * obj){
  free(obj);
}

  uart_func_table uart_func = {
  {
    uart_receive,
    uart_send,
    uart_destroy
  },
  uart_receive_new
  
};

communication *uart_new(){
  uart * obj = (uart *) malloc(sizeof(uart));
  obj->super.func_table =(struct com_func_table *)&uart_func;
  obj->payload = malloc(sizeof(char)*50);
  return (communication *)obj;
}

/*I2C class*/
/*attributes*/
typedef struct{
  communication super;
  char *payload;
  int addr;
}i2c;
/* virtual table function i2c*/
typedef struct{
  com_func_table super;
  void(*receive_new)(communication * obj, char *buffer);
}i2c_func_table;

/*methods*/
void i2c_receive(communication * obj){
  i2c *i2c_obj = (i2c *)obj;
  printf("receive i2c data : %s",i2c_obj->payload );
}
void i2c_receive_new(communication * obj, char * buffer){
  i2c *i2c_obj = (i2c *)obj;
  i2c_obj->payload = buffer;
}
void i2c_send(communication * obj){
  i2c *i2c_obj = (i2c *)obj;
  printf("send i2c data : %s",i2c_obj->payload );
}
void i2c_destroy(communication * obj){
  free(obj);
}
  i2c_func_table i2c_func = {
  {
    i2c_receive,
    i2c_send,
    i2c_destroy
  },
  i2c_receive_new
};
communication *i2c_new(int addr){
  i2c * obj = (i2c *) malloc(sizeof(i2c));
  obj->super.func_table =(struct com_func_table *)&i2c_func;
  obj->payload = malloc(sizeof(char)*50);
  obj->addr = addr;
  return (communication *)obj;
}

/*virtual call (late binding)*/
#define COM_RECEIVE(obj) ((( communication *) ( obj )) -> func_table -> receive (obj))
#define COM_SEND(obj) ((( communication *) ( obj )) -> func_table -> send (obj))
#define UART_RECEIVE_NEW(obj, b) ((uart_func_table *)(( communication *) ( obj )) -> func_table) -> receive_new (obj, b)
#define I2C_RECEIVE_NEW(obj, b) ((i2c_func_table *)(( communication *) ( obj )) -> func_table) -> receive_new (obj, b)
#define COM_DESTROY(obj) ((( communication *) ( obj )) -> func_table -> receive (obj))
 

int main () {

communication *uart_comm;
communication *i2c_comm;
uart_comm = uart_new();
i2c_comm = i2c_new(0x12);

UART_RECEIVE_NEW(uart_comm, "uart payload\n");
COM_RECEIVE(uart_comm);

uart* uart_data = (uart*)uart_comm;
i2c* i2c_data = (i2c*)i2c_comm;
i2c_data->payload = uart_data->payload;

COM_SEND((communication *)i2c_data);


I2C_RECEIVE_NEW(i2c_comm , "i2c payload\n");
COM_RECEIVE(i2c_comm );
uart_data->payload = i2c_data->payload;
COM_SEND((communication *)uart_data);

uart_destroy(uart_comm);
i2c_destroy(i2c_comm);
}
/*
Result:
receive uart data : uart payload
send i2c data : uart payload
receive i2c data : i2c payload
send uart data : i2c payload
*/