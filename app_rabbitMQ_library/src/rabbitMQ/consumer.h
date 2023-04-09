#pragma once
#include "iostream"
#include "AMQPcpp.h"

namespace rabbitMQ
{
	class RabbitMQconsumer
	{
	public:
		AMQPQueue *rabbitMQqueue;

		RabbitMQconsumer();
		~RabbitMQconsumer();
		void consumeMessages(std::string url, std::string queue);
	};
}