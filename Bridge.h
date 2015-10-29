#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

extern YunServer server;

void BSetup();
void digitalCommand(YunClient client);
void analogCommand(YunClient client);
void modeCommand(YunClient client);
