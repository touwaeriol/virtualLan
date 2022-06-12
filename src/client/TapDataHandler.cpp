//
// Created by touwaerio on 2022/6/11.
//

#include "TapDataHandler.h"



vl::client::TapDataHandler::TapDataHandler(vl::client::Client &client, vector<Byte> && data) : _client(client),_data(data){
}
vl::client::TapDataHandler::TapDataHandler(vl::client::TapDataHandler &&tapDataHandler): _client(tapDataHandler._client) , _data(tapDataHandler._data) {

}

vl::client::TapDataHandler::TapDataHandler(const vl::client::TapDataHandler &tapDataHandler): _client(tapDataHandler._client) , _data(tapDataHandler._data) {

}


void vl::client::TapDataHandler::operator()() {
    _client.onReceiveData(_data);
}




