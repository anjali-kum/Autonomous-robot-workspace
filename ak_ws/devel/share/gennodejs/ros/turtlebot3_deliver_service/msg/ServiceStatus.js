// Auto-generated. Do not edit!

// (in-package turtlebot3_deliver_service.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ServiceStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.item_num_chosen_by_pad = null;
      this.is_item_available = null;
      this.robot_service_sequence = null;
    }
    else {
      if (initObj.hasOwnProperty('item_num_chosen_by_pad')) {
        this.item_num_chosen_by_pad = initObj.item_num_chosen_by_pad
      }
      else {
        this.item_num_chosen_by_pad = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('is_item_available')) {
        this.is_item_available = initObj.is_item_available
      }
      else {
        this.is_item_available = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('robot_service_sequence')) {
        this.robot_service_sequence = initObj.robot_service_sequence
      }
      else {
        this.robot_service_sequence = new Array(3).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ServiceStatus
    // Check that the constant length array field [item_num_chosen_by_pad] has the right length
    if (obj.item_num_chosen_by_pad.length !== 3) {
      throw new Error('Unable to serialize array field item_num_chosen_by_pad - length must be 3')
    }
    // Serialize message field [item_num_chosen_by_pad]
    bufferOffset = _arraySerializer.int32(obj.item_num_chosen_by_pad, buffer, bufferOffset, 3);
    // Check that the constant length array field [is_item_available] has the right length
    if (obj.is_item_available.length !== 3) {
      throw new Error('Unable to serialize array field is_item_available - length must be 3')
    }
    // Serialize message field [is_item_available]
    bufferOffset = _arraySerializer.bool(obj.is_item_available, buffer, bufferOffset, 3);
    // Check that the constant length array field [robot_service_sequence] has the right length
    if (obj.robot_service_sequence.length !== 3) {
      throw new Error('Unable to serialize array field robot_service_sequence - length must be 3')
    }
    // Serialize message field [robot_service_sequence]
    bufferOffset = _arraySerializer.int32(obj.robot_service_sequence, buffer, bufferOffset, 3);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ServiceStatus
    let len;
    let data = new ServiceStatus(null);
    // Deserialize message field [item_num_chosen_by_pad]
    data.item_num_chosen_by_pad = _arrayDeserializer.int32(buffer, bufferOffset, 3)
    // Deserialize message field [is_item_available]
    data.is_item_available = _arrayDeserializer.bool(buffer, bufferOffset, 3)
    // Deserialize message field [robot_service_sequence]
    data.robot_service_sequence = _arrayDeserializer.int32(buffer, bufferOffset, 3)
    return data;
  }

  static getMessageSize(object) {
    return 27;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot3_deliver_service/ServiceStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '88c792271484968782eee6bf1d95c178';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[3] item_num_chosen_by_pad
    bool[3] is_item_available
    int32[3] robot_service_sequence
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ServiceStatus(null);
    if (msg.item_num_chosen_by_pad !== undefined) {
      resolved.item_num_chosen_by_pad = msg.item_num_chosen_by_pad;
    }
    else {
      resolved.item_num_chosen_by_pad = new Array(3).fill(0)
    }

    if (msg.is_item_available !== undefined) {
      resolved.is_item_available = msg.is_item_available;
    }
    else {
      resolved.is_item_available = new Array(3).fill(0)
    }

    if (msg.robot_service_sequence !== undefined) {
      resolved.robot_service_sequence = msg.robot_service_sequence;
    }
    else {
      resolved.robot_service_sequence = new Array(3).fill(0)
    }

    return resolved;
    }
};

module.exports = ServiceStatus;
