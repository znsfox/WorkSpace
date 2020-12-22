package com.example.webFlux.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @FileName: User
 * @author: qianBaoLi
 * @date: 2020/11/24 18:57
 * @Description: null
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class User {
    private long id;
    private String name;
    private int age;
}
