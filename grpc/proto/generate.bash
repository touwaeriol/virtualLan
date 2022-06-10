#!/bin/bash


rm -rf ../../include/vl/core/rpc/*.cc
protoc --cpp_out=../../include/vl/core/rpc ./*.proto
protoc --grpc_out=../../include/vl/core/rpc --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`  ./*.proto
rm -rf ../../include/vl/core/rpc/*.cc

rm -rf ../../src/vl/core/rpc/*
protoc --cpp_out=../../src/core/rpc ./*.proto
protoc --grpc_out=../../src/core/rpc --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`  ./*.proto





