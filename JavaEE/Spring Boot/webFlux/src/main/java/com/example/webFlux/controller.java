package com.example.webFlux;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import reactor.core.publisher.Mono;

/**
 * @FileName: controller
 * @author: qianBaoLi
 * @date: 2020/11/24 17:42
 * @Description: null
 */
@RestController
public class controller {
    @GetMapping("/test")
    public Mono<String> test() {
        return Mono.just("this is a webFlux demo");
    }
}
