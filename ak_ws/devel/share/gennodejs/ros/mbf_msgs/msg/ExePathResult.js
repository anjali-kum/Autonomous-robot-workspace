// Auto-generated. Do not edit!

// (in-package mbf_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class ExePathResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.outcome = null;
      this.message = null;
      this.final_pose = null;
      this.dist_to_goal = null;
      this.angle_to_goal = null;
    }
    else {
      if (initObj.hasOwnProperty('outcome')) {
        this.outcome = initObj.outcome
      }
      else {
        this.outcome = 0;
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = '';
      }
      if (initObj.hasOwnProperty('final_pose')) {
        this.final_pose = initObj.final_pose
      }
      else {
        this.final_pose = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('dist_to_goal')) {
        this.dist_to_goal = initObj.dist_to_goal
      }
      else {
        this.dist_to_goal = 0.0;
      }
      if (initObj.hasOwnProperty('angle_to_goal')) {
        this.angle_to_goal = initObj.angle_to_goal
      }
      else {
        this.angle_to_goal = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ExePathResult
    // Serialize message field [outcome]
    bufferOffset = _serializer.uint32(obj.outcome, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    // Serialize message field [final_pose]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.final_pose, buffer, bufferOffset);
    // Serialize message field [dist_to_goal]
    bufferOffset = _serializer.float32(obj.dist_to_goal, buffer, bufferOffset);
    // Serialize message field [angle_to_goal]
    bufferOffset = _serializer.float32(obj.angle_to_goal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ExePathResult
    let len;
    let data = new ExePathResult(null);
    // Deserialize message field [outcome]
    data.outcome = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [final_pose]
    data.final_pose = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [dist_to_goal]
    data.dist_to_goal = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle_to_goal]
    data.angle_to_goal = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.message);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.final_pose);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mbf_msgs/ExePathResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b22f308686bb4e3a7364ea944ef68fd0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    
    # Predefined success codes:
    uint8 SUCCESS         = 0
    # 1..9 are reserved as plugin specific non-error results
    
    # Predefined error codes:
    uint8 FAILURE         = 100  # Unspecified failure, only used for old, non-mfb_core based plugins
    uint8 CANCELED        = 101
    uint8 NO_VALID_CMD    = 102
    uint8 PAT_EXCEEDED    = 103
    uint8 COLLISION       = 104
    uint8 OSCILLATION     = 105
    uint8 ROBOT_STUCK     = 106
    uint8 MISSED_GOAL     = 107
    uint8 MISSED_PATH     = 108
    uint8 BLOCKED_PATH    = 109
    uint8 INVALID_PATH    = 110
    uint8 TF_ERROR        = 111
    uint8 NOT_INITIALIZED = 112
    uint8 INVALID_PLUGIN  = 113
    uint8 INTERNAL_ERROR  = 114
    uint8 OUT_OF_MAP      = 115  # The start and / or the goal are outside the map
    uint8 MAP_ERROR       = 116  # The map is not running properly
    uint8 STOPPED         = 117  # The controller execution has been stopped rigorously.
    
    # 121..149 are reserved as plugin specific errors
    
    uint32 outcome
    string message
    
    geometry_msgs/PoseStamped  final_pose
    float32 dist_to_goal
    float32 angle_to_goal
    
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ExePathResult(null);
    if (msg.outcome !== undefined) {
      resolved.outcome = msg.outcome;
    }
    else {
      resolved.outcome = 0
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = ''
    }

    if (msg.final_pose !== undefined) {
      resolved.final_pose = geometry_msgs.msg.PoseStamped.Resolve(msg.final_pose)
    }
    else {
      resolved.final_pose = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.dist_to_goal !== undefined) {
      resolved.dist_to_goal = msg.dist_to_goal;
    }
    else {
      resolved.dist_to_goal = 0.0
    }

    if (msg.angle_to_goal !== undefined) {
      resolved.angle_to_goal = msg.angle_to_goal;
    }
    else {
      resolved.angle_to_goal = 0.0
    }

    return resolved;
    }
};

// Constants for message
ExePathResult.Constants = {
  SUCCESS: 0,
  FAILURE: 100,
  CANCELED: 101,
  NO_VALID_CMD: 102,
  PAT_EXCEEDED: 103,
  COLLISION: 104,
  OSCILLATION: 105,
  ROBOT_STUCK: 106,
  MISSED_GOAL: 107,
  MISSED_PATH: 108,
  BLOCKED_PATH: 109,
  INVALID_PATH: 110,
  TF_ERROR: 111,
  NOT_INITIALIZED: 112,
  INVALID_PLUGIN: 113,
  INTERNAL_ERROR: 114,
  OUT_OF_MAP: 115,
  MAP_ERROR: 116,
  STOPPED: 117,
}

module.exports = ExePathResult;
