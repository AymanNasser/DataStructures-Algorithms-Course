#include <bits/stdc++.h>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &);
private:
    int size_;
    std::deque <int> finish_time_;
};


Response Buffer::Process(const Request &request){

	int startTime;

	while(this->finish_time_.size() != 0 && this->finish_time_.front() <= request.arrival_time)
	{
		this->finish_time_.pop_front();
	}

	if(this->finish_time_.size() == this->size_ && request.arrival_time < finish_time_.back())
	{
		return Response(true,-1);
	}

	if(this->finish_time_.size() == 0)
		startTime = request.arrival_time;

	else
		startTime = std::max(request.arrival_time,finish_time_.back());


	this->finish_time_.push_back(startTime+request.process_time);

		return Response(false,startTime);
}

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
