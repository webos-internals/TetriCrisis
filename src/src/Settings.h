class Settings
{
public:
	Settings(const int argc, char** argv);
	~Settings();
	
	const char* GetUserName();
	const char* GetHighScoresPath();
	const char* GetUserConfigPath();
	const char* GetDataPath();
	const int GetOptionVerbose();
private:
	int verbose;
	char* username;
	char* highscorespath;
	char* userconfigpath;
	char* runtimebinpath;
	char* datapath;

	int debug_settings_verbose;
};
