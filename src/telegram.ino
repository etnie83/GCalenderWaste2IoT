void telegram(void)
{
#ifdef TELEGRAM
String combinedString = "";
if (_hour >= starttime && _hour <=endtime)
  {
    if (telegramsend == 0)
    {
    message m = bot.getUpdates(); // Read new messages

      if (_spelledtitle == _spelledtitle2)
        {
          combinedString = _spelledtitle + TOMORROW;
        }
      else
        {
          combinedString = _spelledtitle + AND + _spelledtitle2 + TOMORROW;
        }

    bot.sendMessage(m.chat_id, combinedString);  // Send Text of D_WASTE_BLUE
    telegramsend = 1;
    }
  }
  else
  {
      telegramsend = 0;
  }
#endif
}
