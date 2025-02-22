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

class AvailableItemList {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.item_number = null;
      this.is_item_available = null;
    }
    else {
      if (initObj.hasOwnProperty('item_number')) {
        this.item_number = initObj.item_number
      }
      else {
        this.item_number = 0;
      }
      if (initObj.hasOwnProperty('is_item_available')) {
        this.is_item_available = initObj.is_item_available
      }
      else {
        this.is_item_available = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AvailableItemList
    // Serialize message field [item_number]
    bufferOffset = _serializer.uint32(obj.item_number, buffer, bufferOffset);
    // Serialize message field [is_item_available]
    bufferOffset = _serializer.bool(obj.is_item_available, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AvailableItemList
    let len;
    let data = new AvailableItemList(null);
    // Deserialize message field [item_number]
    data.item_number = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [is_item_available]
    data.is_item_available = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot3_deliver_service/AvailableItemList';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4c8abaae09f0bffda0bd8946d2c8b728';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 item_number 
    bool is_item_available
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AvailableItemList(null);
    if (msg.item_number !== undefined) {
      resolved.item_number = msg.item_number;
    }
    else {
      resolved.item_number = 0
    }

    if (msg.is_item_available !== undefined) {
      resolved.is_item_available = msg.is_item_available;
    }
    else {
      resolved.is_item_available = false
    }

    return resolved;
    }
};

module.exports = AvailableItemList;
