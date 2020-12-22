package com.pojo;

import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @FileName: RedPacket
 * @author: qianBaoLi
 * @date: 2020/11/19 15:04
 * @Description: null
 */
@Getter
@Setter
public class RedPacket implements Serializable {
    private Long id;
    private Long userId;
    private Double amount;
    private Timestamp sendDate;
    private Integer total;
    private Double unitAmount;
    private Integer stock;
    private Integer version;
    private String note;
    private static final long serialVersionUID = 1049397724701962381L;
}
