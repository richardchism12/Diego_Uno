
/*
 * Hello World!
 *
 * This is the Hello World! for Arduino. 
 * It shows how to send data to the computer
 */
#ifndef CMD_Interface_h
#define CMD_Interface_h


class CMD_Interface
{
  public:
    void Init();                   // run once, when the sketch starts
    void Serial_Main_Menu_Init();
    void Serial_Main_Menu();                       // run over and over again

  private:
    char rx_byte = 0;
};

#endif
