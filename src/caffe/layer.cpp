#include <boost/thread.hpp>
#include "caffe/layer.hpp"

namespace caffe {

template <typename Dtype>
void Layer<Dtype>::InitMutex() {
  forward_mutex_.reset(new boost::mutex());
}

template <typename Dtype>
void Layer<Dtype>::Lock() {
  if (IsShared()) {
    forward_mutex_->lock();
  }
}

template <typename Dtype>
void Layer<Dtype>::Unlock() {
  if (IsShared()) {
    forward_mutex_->unlock();
  }
}

//template <typename Dtype>
//int Layer<Dtype>::get_data_pos() {
//	return 0;
//}

INSTANTIATE_CLASS(Layer);

}  // namespace caffe
