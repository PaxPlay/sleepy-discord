#include "channel.h"

namespace SleepyDiscord {
	Channel::Channel(const std::string * rawJson) {
		//default values
		bitrate = 0;
		userLimit = 0;   //this only matters on voice channels
		topic = "";
		lastMessage_id = "";

		std::initializer_list<const char *const> names = {
			"id", "guild_id", "name", "type", "position", "is_private",
			"permission_overwrites", "topic", "last_message_id", "bitrate", "user_limit"
		};

		std::vector<std::string> values = json::getValues(rawJson->c_str(), names);
		id                   =            values[index(names, "id"                   )] ;
		guild_id             =            values[index(names, "guild_id"             )] ;
		name                 =            values[index(names, "name"                 )] ;
		type                 =            values[index(names, "type"                 )] ;
		position             = std::stoi( values[index(names, "position"             )]);
		isPrivate            = getBool(   values[index(names, "is_private"           )]);
		permissionOverwrites = Overwrite(&values[index(names, "permission_overwrites")]);
		topic                =            values[index(names, "topic"                )] ;
		lastMessage_id       =            values[index(names, "last_message_id"      )] ;
		bitrate              = std::stoi( values[index(names, "bitrate"              )]);
		userLimit            = std::stoi( values[index(names, "user_limit"           )]);
	}

	Channel::~Channel() {

	}

	DirectMessageChannel::~DirectMessageChannel() {

	}

	DirectMessageChannel::DirectMessageChannel(const std::string * rawJson) {
		std::initializer_list<const char *const> names = {
			"id", "is_private", "recipient", "last_message_id"
		};
		std::vector<std::string> values = json::getValues(rawJson->c_str(), names);
		id             =         values[index(names, "id"             )] ;
		is_private     = getBool(values[index(names, "is_private"     )]);
		recipient      = User(  &values[index(names, "recipient"      )]);
		lastMessage_id =         values[index(names, "last_message_id")] ;
	}

	Overwrite::Overwrite(const std::string * rawJson) {
		std::initializer_list<const char *const> names = {
			"id", "type", "allow", "deny"
		};
		std::vector<std::string> values = json::getValues(rawJson->c_str(), names);
		id    =           values[index(names, "id"   )] ;
		type  =           values[index(names, "type" )] ;
		allow = std::stoi(values[index(names, "allow")]);
		deny  = std::stoi(values[index(names, "deny" )]);
	}
}