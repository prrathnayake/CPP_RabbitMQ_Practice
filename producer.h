#pragma once
#include "iostream"
#include "AMQPcpp.h"

namespace rabbitMQ
{
    class RabbitMQprocuder
    {
    private:
        AMQPExchange *rabbitMQexchange;

    public:
        RabbitMQprocuder(std::string url, std::string exchange, std::string queue);
        void produceMessage(std::string message);
        ~RabbitMQprocuder();
    };
}