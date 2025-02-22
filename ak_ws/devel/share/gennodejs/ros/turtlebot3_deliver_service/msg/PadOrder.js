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

class PadOrder {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pad_number = null;
      this.item_number = null;
    }
    else {
      if (initObj.hasOwnProperty('pad_number')) {
        this.pad_number = initObj.pad_number
      }
      else {
        this.pad_number = 0;
      }
      if (initObj.hasOwnProperty('item_number')) {
        this.item_number = initObj.item_number
      }
      else {
        this.item_number = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PadOrder
    // Serialize message field [pad_number]
    bufferOffset = _serializer.uint32(obj.pad_number, buffer, bufferOffset);
    // Serialize message field [item_number]
    bufferOffset = _serializer.uint32(obj.item_number, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PadOrder
    let len;
    let data = new PadOrder(null);
    // Deserialize message field [pad_number]
    data.pad_number = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [item_number]
    data.item_number = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot3_deliver_service/PadOrder';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f312fcf0d154bf3751121cfb69eca080';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 pad_number
    uint32 item_number
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PadOrder(null);
    if (msg.pad_number !== undefined) {
      resolved.pad_number = msg.pad_number;
    }
    else {
      resolved.pad_number = 0
    }

    if (msg.item_number !== undefined) {
      resolved.item_number = msg.item_number;
    }
    else {
      resolved.item_number = 0
    }

    return resolved;
    }
};

module.exports = PadOrder;
