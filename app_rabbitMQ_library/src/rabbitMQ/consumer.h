#pragma once
#include "iostream"
#include "AMQPcpp.h"

namespace rabbitMQ
{
	class RabbitMQconsumer
	{
	public:
		AMQPQueue *rabbitMQqueue;

		RabbitMQconsumer(std::string url, std::string queue);
		~RabbitMQconsumer();
		void consumeMessages();
	};
}