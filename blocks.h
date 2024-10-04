#define COMMAND_TIME "date +'%d/%m/%y %a %R'"
#define COMMAND_CPU  "vmstat 1 2|tail -1|awk '{printf \"%d%%\", 100-$15}'"
#define COMMAND_HDD  "df -h|grep -e /dev/sda3 |awk '{printf \"%s/%s\", $3, $4}'"
#define COMMAND_RAM  "free -h | grep -e \"Mem\"| awk '{printf \"%s/%s\", $3, $2}'"
#define COMMAND_LANG "xset -q|grep LED| awk '{if (substr ($10,5,1) == 1) print \"[RU]\"; else print \"[EN]\";}'"
#define COMMAND_VOLM "wpctl get-volume @DEFAULT_SINK@ | awk '{if ($3 == \"[MUTED]\") print \"[M]\"; else printf \"%s%%\", $2}'"
#define COMMAND_NET  "networkctl status | grep \"State\" | awk '{print $3}'"

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
  /*Icon*/  /*Command*/   /*Update Interval*/ /*Update Signal*/
  {"HDD: ", COMMAND_HDD,          30,                  0},
  {"RAM: ", COMMAND_RAM,          15,                  0},
  {"CPU: ", COMMAND_CPU,          15,                  0},
  {"VOL: ", COMMAND_VOLM,          0,                  1},
  {"NET: ", COMMAND_NET,           5,                  0},
  {"",      COMMAND_LANG,          0,                  1},
  {"",      COMMAND_TIME,          5,                  0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
